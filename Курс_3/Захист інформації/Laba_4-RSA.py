"""
513-і, Золотухін Андрій
Захист інформації. Лабораторна робота 4. Алгоритми з відкритим ключем RSA

  RSA — асиметричний алгоритм шифрування (1977, Рівест, Шамір, Адлеман).

  Принцип:
    1. Генеруються два великих простих числа p та q
    2. n = p * q  (модуль)
    3. φ(n) = (p-1)*(q-1)  (функція Ейлера)
    4. Обирається e: 1 < e < φ(n), НСД(e, φ(n)) = 1
    5. Обчислюється d: d*e ≡ 1 (mod φ(n))  (обернений елемент)

  Публічний ключ : (e, n)
  Секретний ключ : (d, n)

  Шифрування  : C = M^e mod n
  Дешифрування: M = C^d mod n
"""

import random
import math

# ──────────────────────────────────────────────────────────
# Математичні допоміжні функції
# ──────────────────────────────────────────────────────────

def gcd(a, b):
    """Найбільший спільний дільник (алгоритм Евкліда)."""
    while b:
        a, b = b, a % b
    return a


def extended_gcd(a, b):
    """
    Розширений алгоритм Евкліда.
    Повертає (g, x, y) такі що: a*x + b*y = g = НСД(a, b)
    """
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y


def mod_inverse(e, phi):
    """
    Мультиплікативний обернений елемент e за модулем phi.
    Тобто знаходить d таке що: e*d ≡ 1 (mod phi)
    """
    g, x, _ = extended_gcd(e, phi)
    if g != 1:
        raise ValueError("Обернений елемент не існує (e та phi не взаємно прості)")
    return x % phi


def power_mod(base, exp, mod):
    """
    Швидке піднесення до степеня за модулем.
    base^exp mod mod — метод швидкого множення (квадрат і множення).
    Не використовує вбудований pow() з трьома аргументами.
    """
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:          # якщо поточний біт степеня = 1
            result = (result * base) % mod
        exp = exp // 2
        base = (base * base) % mod
    return result


# ──────────────────────────────────────────────────────────
# Тест Міллера–Рабіна на простоту
# Значно швидший за пробний поділ для великих чисел
# ──────────────────────────────────────────────────────────

def miller_rabin(n, k=10):
    """
    Імовірнісний тест простоти Міллера–Рабіна.
    k — кількість раундів (чим більше, тим точніше).
    Повертає True якщо n ймовірно просте, False якщо складене.
    """
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False

    # Записуємо n-1 у вигляді 2^r * d
    r, d = 0, n - 1
    while d % 2 == 0:
        r += 1
        d //= 2

    # k раундів тесту
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = power_mod(a, d, n)

        if x == 1 or x == n - 1:
            continue

        for _ in range(r - 1):
            x = power_mod(x, 2, n)
            if x == n - 1:
                break
        else:
            return False  # складене

    return True  # ймовірно просте


def generate_prime(bits=512):
    """
    Генерує випадкове просте число заданої розрядності.
    bits — кількість біт (512 за замовчуванням для навчальних цілей).
    """
    while True:
        # Генеруємо непарне випадкове число потрібної розрядності
        n = random.getrandbits(bits)
        n |= (1 << (bits - 1))  # встановлюємо старший біт
        n |= 1                  # робимо непарним
        if miller_rabin(n):
            return n


# ──────────────────────────────────────────────────────────
# Генерація ключів RSA
# ──────────────────────────────────────────────────────────

def generate_keys(bits=512):
    """
    Генерація пари ключів RSA.
    bits — розрядність кожного простого числа p та q.

    Повертає:
      public_key  = (e, n)
      private_key = (d, n)
    """
    print("  Генерація простих чисел p та q...", end=' ', flush=True)

    # Генеруємо два різних прості числа
    p = generate_prime(bits)
    q = generate_prime(bits)
    while q == p:
        q = generate_prime(bits)

    print("готово.")

    n = p * q                    # модуль RSA
    phi = (p - 1) * (q - 1)     # функція Ейлера

    # Обираємо відкриту експоненту e
    # Стандартне значення: 65537 (просте, ефективне для піднесення до степеня)
    e = 65537
    if gcd(e, phi) != 1:
        # Якщо 65537 не підходить — підбираємо інше
        e = 3
        while gcd(e, phi) != 1:
            e += 2

    # Обчислюємо секретну експоненту d
    d = mod_inverse(e, phi)

    return (e, n), (d, n)


# ──────────────────────────────────────────────────────────
# Шифрування та дешифрування
# RSA працює з числами, тому текст перетворюємо у байти,
# потім у числа (по одному байту або блоками)
# ──────────────────────────────────────────────────────────

def encrypt(plaintext: str, public_key: tuple) -> list:
    """
    Шифрування тексту публічним ключем.
    Кожен байт тексту шифрується окремо: C = M^e mod n
    Повертає список зашифрованих чисел.
    """
    e, n = public_key
    return [power_mod(byte, e, n) for byte in plaintext.encode('utf-8')]


def decrypt(ciphertext: list, private_key: tuple) -> str:
    """
    Дешифрування списку чисел секретним ключем.
    M = C^d mod n
    Повертає розшифрований рядок.
    """
    d, n = private_key
    decrypted_bytes = bytes([power_mod(c, d, n) for c in ciphertext])
    return decrypted_bytes.decode('utf-8')


def ciphertext_to_hex(ciphertext: list) -> str:
    """Перетворює список зашифрованих чисел у hex-рядок для виводу."""
    return ' '.join(f'{c:x}' for c in ciphertext)


# ──────────────────────────────────────────────────────────
# ГОЛОВНА ПРОГРАМА
# ──────────────────────────────────────────────────────────

def main():
    print("=" * 60)
    print("        ШИФР RSA — Лабораторна робота")
    print("=" * 60)

    plaintext = input("\nВведіть текст для шифрування : ").strip()
    if not plaintext:
        print("Помилка: текст не може бути порожнім!")
        return

    # Генерація ключів
    print("\n[ Генерація ключів ]")
    print("  Розрядність ключа: 512 біт")
    public_key, private_key = generate_keys(bits=512)
    e, n = public_key
    d, _ = private_key

    print(f"\n  Публічний ключ (e, n):")
    print(f"    e = {e}")
    print(f"    n = {n}")
    print(f"\n  Секретний ключ (d, n):")
    print(f"    d = {d}")
    print(f"    n = {n}")

    # Шифрування
    print("\n[ Шифрування ]")
    print(f"  Відкритий текст  : {plaintext}")
    print("  Шифрування...", end=' ', flush=True)
    ciphertext = encrypt(plaintext, public_key)
    print("готово.")
    print(f"  Шифротекст (hex) :")
    # Виводимо по 3 числа на рядок для читабельності
    hex_values = [f'{c:x}' for c in ciphertext]
    for i in range(0, len(hex_values), 3):
        print(f"    {' | '.join(hex_values[i:i+3])}")

    # Дешифрування
    print("\n[ Дешифрування ]")
    print("  Дешифрування...", end=' ', flush=True)
    decrypted = decrypt(ciphertext, private_key)
    print("готово.")
    print(f"  Розшифрований текст : {decrypted}")

    # Перевірка
    print("\n[ Перевірка ]")
    if plaintext == decrypted:
        print("  ✓ OK — розшифрований текст збігається з оригіналом.")
    else:
        print("  ✗ Помилка!")

    print("=" * 60)


if __name__ == "__main__":
    main()
