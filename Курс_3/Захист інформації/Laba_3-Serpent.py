"""
513-і, Золотухін Андрій
Захист інформації. Лабораторна робота 3. Розробити програму-шифратор за допомогою шифру Serpent
Варіант 8:  Слово='Аполлон',  Ключ ='Равлик' 
"""

import struct

# ──────────────────────────────────────────────────────────
# 8 S-блоків Serpent (кожен: 16 входів → 16 виходів)
# Використовуються циклічно: раунд r → S_BOX[r % 8]
# ──────────────────────────────────────────────────────────

S_BOX = [
    [3,8,15,1,10,6,5,11,14,13,4,2,7,0,9,12],   # S0
    [15,12,2,7,9,0,5,10,1,11,14,8,6,13,3,4],   # S1
    [8,6,7,9,3,12,10,15,13,1,14,4,0,11,5,2],   # S2
    [0,15,11,8,12,9,6,3,13,1,2,4,10,7,5,14],   # S3
    [1,15,8,3,12,0,11,6,2,5,4,10,9,14,7,13],   # S4
    [15,5,2,11,4,10,9,12,0,3,14,8,13,6,7,1],   # S5
    [7,2,12,5,8,4,6,11,14,9,1,15,13,3,10,0],   # S6
    [1,13,15,0,14,8,2,11,7,4,12,10,9,3,5,6],   # S7
]

# Обернені S-блоки для дешифрування (будуються автоматично)
S_BOX_INV = []
for _s in S_BOX:
    _inv = [0] * 16
    for _i, _v in enumerate(_s):
        _inv[_v] = _i
    S_BOX_INV.append(_inv)

MASK32 = 0xFFFFFFFF
PHI    = 0x9e3779b9   # дробова частина золотого перетину × 2^32


# ──────────────────────────────────────────────────────────
# Допоміжні функції
# ──────────────────────────────────────────────────────────

def rol32(x, n):
    """Циклічний зсув 32-бітного числа вліво."""
    return ((x << n) | (x >> (32 - n))) & MASK32

def ror32(x, n):
    """Циклічний зсув 32-бітного числа вправо."""
    return ((x >> n) | (x << (32 - n))) & MASK32


# ──────────────────────────────────────────────────────────
# Застосування S-блоку до чотирьох 32-бітних слів
#
# Serpent працює з бітовими зрізами (bitslice):
# блок 128 біт = 4 слова по 32 біти (a, b, c, d).
# S-блок застосовується до кожної з 32 "вертикальних"
# груп по 4 біти (по одному біту з кожного слова).
# ──────────────────────────────────────────────────────────

def apply_sbox(r, a, b, c, d):
    """
    Застосовує S-блок раунду r до чотирьох слів (a,b,c,d).
    Повертає чотири нових слова.
    """
    sbox = S_BOX[r % 8]
    ra = rb = rc = rd = 0
    for i in range(32):
        # Збираємо 4-бітний індекс з i-го біту кожного слова
        nibble = ((a >> i) & 1)       | \
                 (((b >> i) & 1) << 1) | \
                 (((c >> i) & 1) << 2) | \
                 (((d >> i) & 1) << 3)
        out = sbox[nibble]
        # Розкладаємо результат назад по словах
        ra |= ((out     ) & 1) << i
        rb |= ((out >> 1) & 1) << i
        rc |= ((out >> 2) & 1) << i
        rd |= ((out >> 3) & 1) << i
    return ra, rb, rc, rd


def apply_sbox_inv(r, a, b, c, d):
    """Застосовує обернений S-блок раунду r (для дешифрування)."""
    sbox = S_BOX_INV[r % 8]
    ra = rb = rc = rd = 0
    for i in range(32):
        nibble = ((a >> i) & 1)       | \
                 (((b >> i) & 1) << 1) | \
                 (((c >> i) & 1) << 2) | \
                 (((d >> i) & 1) << 3)
        out = sbox[nibble]
        ra |= ((out     ) & 1) << i
        rb |= ((out >> 1) & 1) << i
        rc |= ((out >> 2) & 1) << i
        rd |= ((out >> 3) & 1) << i
    return ra, rb, rc, rd


# ──────────────────────────────────────────────────────────
# Лінійне перетворення
# Забезпечує дифузію — перемішування бітів між словами
# ──────────────────────────────────────────────────────────

def linear_transform(a, b, c, d):
    """Лінійне перетворення Serpent (між раундами)."""
    a = rol32(a, 13)
    c = rol32(c, 3)
    b = b ^ a ^ c
    d = d ^ c ^ ((a << 3) & MASK32)
    b = rol32(b, 1)
    d = rol32(d, 7)
    a = a ^ b ^ d
    c = c ^ d ^ ((b << 7) & MASK32)
    a = rol32(a, 5)
    c = rol32(c, 22)
    return a, b, c, d


def linear_transform_inv(a, b, c, d):
    """Обернене лінійне перетворення (для дешифрування)."""
    c = ror32(c, 22)
    a = ror32(a, 5)
    c = c ^ d ^ ((b << 7) & MASK32)
    a = a ^ b ^ d
    d = ror32(d, 7)
    b = ror32(b, 1)
    d = d ^ c ^ ((a << 3) & MASK32)
    b = b ^ a ^ c
    c = ror32(c, 3)
    a = ror32(a, 13)
    return a, b, c, d


# ──────────────────────────────────────────────────────────
# Розширення ключа (Key Schedule)
# Генерує 33 підключі по 128 біт (4 слова × 33)
# ──────────────────────────────────────────────────────────

def key_schedule(key: bytes):
    """
    Генерація 33 раундових підключів з ключа.
    Ключ доповнюється до 16 байт якщо коротший.
    Повертає список з 33 кортежів (a, b, c, d).
    """
    # Доповнення ключа до 16 байт
    key = key[:16].ljust(16, b'\x00')

    # Розбиваємо на 4 слова (little-endian)
    k = list(struct.unpack('<4I', key))

    # Доповнюємо до 8 слів для алгоритму розширення:
    # додаємо '1' одразу після ключа (padding за специфікацією)
    k += [1, 0, 0, 0]

    # Генеруємо 132 проміжних слова за формулою Serpent
    w = k[:]
    for i in range(8, 140):
        val = w[i-8] ^ w[i-5] ^ w[i-3] ^ w[i-1] ^ PHI ^ (i - 8)
        w.append(rol32(val, 11))

    # Формуємо 33 підключі, пропускаючи через S-блоки
    subkeys = []
    for i in range(33):
        a, b, c, d = apply_sbox((35 - i) % 8,
                                 w[4*i], w[4*i+1], w[4*i+2], w[4*i+3])
        subkeys.append((a, b, c, d))

    return subkeys


# ──────────────────────────────────────────────────────────
# Шифрування / дешифрування блоку
# ──────────────────────────────────────────────────────────

def encrypt_block(block: bytes, subkeys: list) -> bytes:
    """Шифрування одного блоку 16 байт (128 біт)."""
    a, b, c, d = struct.unpack('<4I', block)

    for r in range(32):
        # XOR з підключем раунду
        ka, kb, kc, kd = subkeys[r]
        a ^= ka; b ^= kb; c ^= kc; d ^= kd

        # S-блок
        a, b, c, d = apply_sbox(r, a, b, c, d)

        # Лінійне перетворення (крім останнього раунду)
        if r < 31:
            a, b, c, d = linear_transform(a, b, c, d)

    # Фінальний XOR з підключем 32
    ka, kb, kc, kd = subkeys[32]
    a ^= ka; b ^= kb; c ^= kc; d ^= kd

    return struct.pack('<4I', a, b, c, d)


def decrypt_block(block: bytes, subkeys: list) -> bytes:
    """Дешифрування одного блоку 16 байт (128 біт)."""
    a, b, c, d = struct.unpack('<4I', block)

    # Фінальний XOR у зворотньому порядку
    ka, kb, kc, kd = subkeys[32]
    a ^= ka; b ^= kb; c ^= kc; d ^= kd

    for r in range(31, -1, -1):
        # Обернений S-блок
        a, b, c, d = apply_sbox_inv(r, a, b, c, d)

        # XOR з підключем
        ka, kb, kc, kd = subkeys[r]
        a ^= ka; b ^= kb; c ^= kc; d ^= kd

        # Обернене лінійне перетворення (крім останнього зворотного раунду)
        if r > 0:
            a, b, c, d = linear_transform_inv(a, b, c, d)

    return struct.pack('<4I', a, b, c, d)


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

def serpent_encrypt(plaintext: str, keyword: str) -> bytes:
    """Зашифрувати рядок, повернути байти."""
    subkeys = key_schedule(make_key(keyword))
    data = pad(plaintext.encode('utf-8'))
    return b''.join(encrypt_block(data[i:i+16], subkeys)
                    for i in range(0, len(data), 16))

def serpent_decrypt(ciphertext: bytes, keyword: str) -> str:
    """Розшифрувати байти, повернути рядок."""
    subkeys = key_schedule(make_key(keyword))
    result = b''.join(decrypt_block(ciphertext[i:i+16], subkeys)
                      for i in range(0, len(ciphertext), 16))
    return unpad(result).decode('utf-8')


# ──────────────────────────────────────────────────────────
# ГОЛОВНА ПРОГРАМА
# ──────────────────────────────────────────────────────────

def main():
    print("=" * 55)
    print("       ШИФР SERPENT — Лабораторна робота")
    print("=" * 55)

    plaintext = input("\nВведіть слово для шифрування : ").strip()
    keyword   = input("Введіть слово-ключ           : ").strip()

    if not plaintext or not keyword:
        print("Помилка: текст та ключ не можуть бути порожніми!")
        return

    print(f"\n  Відкритий текст : {plaintext}")
    print(f"  Ключ            : {keyword}")

    encrypted = serpent_encrypt(plaintext, keyword)
    print(f"\n  Зашифровано (hex) : {encrypted.hex()}")

    decrypted = serpent_decrypt(encrypted, keyword)
    print(f"  Розшифровано      : {decrypted}")

    ok = plaintext == decrypted
    print(f"\n  Перевірка: {'✓ OK — тексти збігаються' if ok else '✗ Помилка'}")
    print("=" * 55)


if __name__ == "__main__":
    main()
