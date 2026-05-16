"""
=============================================================
  ЛАБОРАТОРНА РОБОТА
  Тема: Симетричне шифрування
  Алгоритм: Шифр Rijndael (AES)
  Мова: Python
  Бібліотеки: тільки стандартні (struct) — без pycryptodome,
              cryptography та інших crypto-бібліотек
=============================================================

  Rijndael — блоковий шифр, обраний стандартом AES у 2001 році.
  Розмір блоку: 128 біт (16 байт)
  Розмір ключа: 128 біт (16 байт) — у цій реалізації

  Структура одного раунду:
    1. SubBytes    — байтова підстановка через S-блок
    2. ShiftRows   — циклічний зсув рядків стану
    3. MixColumns  — множення стовпців на матрицю у GF(2^8)
    4. AddRoundKey — XOR з раундовим підключем
"""

import struct

# ──────────────────────────────────────────────────────────
# S-блок Rijndael та обернений S-блок
# Побудовані на основі мультиплікативного оберненого у GF(2^8)
# та афінного перетворення
# ──────────────────────────────────────────────────────────

S_BOX = [
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
    0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
    0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
    0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
    0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
    0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
    0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
    0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
    0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
    0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
    0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
    0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
    0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
    0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16,
]

S_BOX_INV = [0] * 256
for _i, _v in enumerate(S_BOX):
    S_BOX_INV[_v] = _i

# Таблиця раундових констант (RCON) для розширення ключа
RCON = [0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36]


# ──────────────────────────────────────────────────────────
# Операції у полі GF(2^8)
# Поліном: x^8 + x^4 + x^3 + x + 1 (0x11b)
# ──────────────────────────────────────────────────────────

def xtime(a):
    """Множення на x (тобто на 2) у GF(2^8)."""
    return ((a << 1) ^ 0x1b) & 0xFF if a & 0x80 else (a << 1) & 0xFF

def gf_mul(a, b):
    """Множення двох елементів у GF(2^8)."""
    r = 0
    for _ in range(8):
        if b & 1:
            r ^= a
        a = xtime(a)
        b >>= 1
    return r


# ──────────────────────────────────────────────────────────
# Стан Rijndael — матриця 4×4 байти
# Подається як список з 16 байт (рядки → стовпці)
# ──────────────────────────────────────────────────────────

def bytes_to_state(b):
    """Перетворює 16 байт у матрицю стану 4×4 (по стовпцях)."""
    return [[b[r + 4*c] for c in range(4)] for r in range(4)]

def state_to_bytes(s):
    """Перетворює матрицю стану 4×4 у 16 байт."""
    return bytes(s[r][c] for c in range(4) for r in range(4))


# ──────────────────────────────────────────────────────────
# Чотири операції одного раунду
# ──────────────────────────────────────────────────────────

def sub_bytes(state):
    """SubBytes — замінює кожен байт через S-блок."""
    return [[S_BOX[state[r][c]] for c in range(4)] for r in range(4)]

def sub_bytes_inv(state):
    """Обернений SubBytes — через обернений S-блок."""
    return [[S_BOX_INV[state[r][c]] for c in range(4)] for r in range(4)]


def shift_rows(state):
    """ShiftRows — циклічний зсув рядків вліво на r позицій."""
    return [
        [state[r][(c + r) % 4] for c in range(4)]
        for r in range(4)
    ]

def shift_rows_inv(state):
    """Обернений ShiftRows — зсув вправо."""
    return [
        [state[r][(c - r) % 4] for c in range(4)]
        for r in range(4)
    ]


def mix_columns(state):
    """
    MixColumns — кожен стовпець множиться на фіксовану матрицю
    у GF(2^8):
      [2 3 1 1]
      [1 2 3 1]
      [1 1 2 3]
      [3 1 1 2]
    """
    result = [[0]*4 for _ in range(4)]
    for c in range(4):
        s = [state[r][c] for r in range(4)]
        result[0][c] = gf_mul(2,s[0]) ^ gf_mul(3,s[1]) ^ s[2]         ^ s[3]
        result[1][c] = s[0]           ^ gf_mul(2,s[1]) ^ gf_mul(3,s[2]) ^ s[3]
        result[2][c] = s[0]           ^ s[1]           ^ gf_mul(2,s[2]) ^ gf_mul(3,s[3])
        result[3][c] = gf_mul(3,s[0]) ^ s[1]           ^ s[2]           ^ gf_mul(2,s[3])
    return result

def mix_columns_inv(state):
    """
    Обернений MixColumns — множення на обернену матрицю:
      [14 11 13  9]
      [ 9 14 11 13]
      [13  9 14 11]
      [11 13  9 14]
    """
    result = [[0]*4 for _ in range(4)]
    for c in range(4):
        s = [state[r][c] for r in range(4)]
        result[0][c] = gf_mul(14,s[0]) ^ gf_mul(11,s[1]) ^ gf_mul(13,s[2]) ^ gf_mul(9, s[3])
        result[1][c] = gf_mul(9, s[0]) ^ gf_mul(14,s[1]) ^ gf_mul(11,s[2]) ^ gf_mul(13,s[3])
        result[2][c] = gf_mul(13,s[0]) ^ gf_mul(9, s[1]) ^ gf_mul(14,s[2]) ^ gf_mul(11,s[3])
        result[3][c] = gf_mul(11,s[0]) ^ gf_mul(13,s[1]) ^ gf_mul(9, s[2]) ^ gf_mul(14,s[3])
    return result


def add_round_key(state, round_key):
    """AddRoundKey — XOR стану з раундовим підключем."""
    return [[state[r][c] ^ round_key[r][c] for c in range(4)] for r in range(4)]


# ──────────────────────────────────────────────────────────
# Розширення ключа (Key Expansion)
# З 16-байтного ключа генеруються 11 підключів по 128 біт
# ──────────────────────────────────────────────────────────

def key_expansion(key: bytes):
    """
    Генерація 11 раундових підключів для AES-128.
    Повертає список з 11 матриць стану 4×4.
    """
    # Початкові 4 слова (по 4 байти кожне)
    w = [list(key[4*i:4*i+4]) for i in range(4)]

    for i in range(4, 44):
        temp = w[i-1][:]
        if i % 4 == 0:
            # RotWord — циклічний зсув слова вліво на 1 байт
            temp = temp[1:] + temp[:1]
            # SubWord — S-блок до кожного байту
            temp = [S_BOX[b] for b in temp]
            # XOR з раундовою константою
            temp[0] ^= RCON[i // 4 - 1]
        w.append([w[i-4][j] ^ temp[j] for j in range(4)])

    # Формуємо 11 підключів у вигляді матриць 4×4
    subkeys = []
    for rnd in range(11):
        rk = [[w[4*rnd + c][r] for c in range(4)] for r in range(4)]
        subkeys.append(rk)

    return subkeys


# ──────────────────────────────────────────────────────────
# Шифрування / дешифрування блоку
# ──────────────────────────────────────────────────────────

def encrypt_block(block: bytes, subkeys: list) -> bytes:
    """Шифрування одного блоку 16 байт (10 раундів AES-128)."""
    state = bytes_to_state(block)

    # Початковий AddRoundKey
    state = add_round_key(state, subkeys[0])

    # 9 повних раундів
    for r in range(1, 10):
        state = sub_bytes(state)
        state = shift_rows(state)
        state = mix_columns(state)
        state = add_round_key(state, subkeys[r])

    # Фінальний раунд (без MixColumns)
    state = sub_bytes(state)
    state = shift_rows(state)
    state = add_round_key(state, subkeys[10])

    return state_to_bytes(state)


def decrypt_block(block: bytes, subkeys: list) -> bytes:
    """Дешифрування одного блоку 16 байт."""
    state = bytes_to_state(block)

    state = add_round_key(state, subkeys[10])

    for r in range(9, 0, -1):
        state = shift_rows_inv(state)
        state = sub_bytes_inv(state)
        state = add_round_key(state, subkeys[r])
        state = mix_columns_inv(state)

    # Фінальний раунд
    state = shift_rows_inv(state)
    state = sub_bytes_inv(state)
    state = add_round_key(state, subkeys[0])

    return state_to_bytes(state)


# ──────────────────────────────────────────────────────────
# Padding та підготовка ключа
# ──────────────────────────────────────────────────────────

def pad(data: bytes) -> bytes:
    """PKCS#7 padding до кратного 16 байт."""
    n = 16 - len(data) % 16
    return data + bytes([n] * n)

def unpad(data: bytes) -> bytes:
    """Видалення PKCS#7 padding."""
    return data[:-data[-1]]

def make_key(keyword: str) -> bytes:
    """Отримує 16-байтний ключ зі слова-ключа."""
    raw = keyword.encode('utf-8')
    if len(raw) < 16:
        raw = (raw * (16 // len(raw) + 1))[:16]
    return raw[:16]


# ──────────────────────────────────────────────────────────
# Публічний інтерфейс
# ──────────────────────────────────────────────────────────

def rijndael_encrypt(plaintext: str, keyword: str) -> bytes:
    """Зашифрувати рядок, повернути байти."""
    subkeys = key_expansion(make_key(keyword))
    data = pad(plaintext.encode('utf-8'))
    return b''.join(encrypt_block(data[i:i+16], subkeys)
                    for i in range(0, len(data), 16))

def rijndael_decrypt(ciphertext: bytes, keyword: str) -> str:
    """Розшифрувати байти, повернути рядок."""
    subkeys = key_expansion(make_key(keyword))
    result = b''.join(decrypt_block(ciphertext[i:i+16], subkeys)
                      for i in range(0, len(ciphertext), 16))
    return unpad(result).decode('utf-8')


# ──────────────────────────────────────────────────────────
# ГОЛОВНА ПРОГРАМА
# ──────────────────────────────────────────────────────────

def main():
    print("=" * 55)
    print("      ШИФР RIJNDAEL (AES) — Лабораторна робота")
    print("=" * 55)

    plaintext = input("\nВведіть слово для шифрування : ").strip()
    keyword   = input("Введіть слово-ключ           : ").strip()

    if not plaintext or not keyword:
        print("Помилка: текст та ключ не можуть бути порожніми!")
        return

    print(f"\n  Відкритий текст : {plaintext}")
    print(f"  Ключ            : {keyword}")

    encrypted = rijndael_encrypt(plaintext, keyword)
    print(f"\n  Зашифровано (hex) : {encrypted.hex()}")

    decrypted = rijndael_decrypt(encrypted, keyword)
    print(f"  Розшифровано      : {decrypted}")

    ok = plaintext == decrypted
    print(f"\n  Перевірка: {'✓ OK — тексти збігаються' if ok else '✗ Помилка'}")
    print("=" * 55)


if __name__ == "__main__":
    main()
