#include <iostream>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251); //підтримка виведення кирилицею
    int n, r100, r10, r1, n2;
    
    // 2.2.4. Самостійна робота

    cout << "1.1. Дано час у днях. Знайти кількість повних років у ньому." << endl;
    cout << "час у днях = ";
    cin >> n;
    cout << "кількість повних років " << n / 365 << '\n' << endl;
    
    cout << "1.2. Дано масу в кілограмах. Знайти кількість повних центнерів у ній." << endl;
    cout << "масу в кілограмах = ";
    cin >> n;
    cout << "кількість повних центнерів " << n / 100 << '\n' << endl;
    
    cout << "1.3. Дано масу в кілограмах. Знайти кількість повних тон у ній." << endl;
    cout << "масу в кілограмах = ";
    cin >> n;
    cout << "кількість повних тон " << n / 1000 << '\n' << endl;
    
    cout << "1.4. Дана відстань за метри. Знайти кількість повних кілометрів у ньому." << endl;
    cout << "відстань за метри = ";
    cin >> n;
    cout << "кількість повних кілометрів " << n / 1000 << '\n' << endl;
    
    cout << "1.5. З деякого моменту минуло 234 дні. Скільки повних тижнів минуло за цей період ?" << endl;
    cout << "234 дні дорівнює повних тижнів " << 234 / 7 << '\n' << endl;
    
    cout << "1.6. З початку доби минуло п секунд. Визначити, скільки повних годин пройшло з початку доби" << endl;
    cout << "З початку доби минуло секунд = ";
    cin >> n;
    cout << "повних годин пройшло " << n / (60 * 60) << '\n' << endl;
    
    cout << "1.6. 1.7. З початку доби минуло п секунд. Визначити, скільки повних хвилин пройшло з початку чергової години" << endl;
    cout << "З початку доби минуло секунд = ";
    cin >> n;
    cout << "повних хвилин пройшло з початку чергової години " << (n % (60 * 60)) / 60 << '\n' << endl;
    
    cout << "1.8. З початку доби минуло п секунд. Визначити скільки повних секунд пройшло з початку чергової хвилини" << endl;
    cout << "З початку доби минуло секунд = ";
    cin >> n;
    cout << "повних секунд пройшло з початку чергової хвилини " << n % 60 << '\n' << endl;
    
    cout << "1.9. Даний прямокутник із розмірами 543x130 мм. Скільки квадратів із стороною 130 мм можна відрізати від нього ?" << endl;
    cout << "прямокутник із розмірами 543x130, квадратів із стороною 130 мм можна відрізати " << 543 / 130 << '\n' << endl;
    
    cout << "1.10. Дана відстань у дециметрах. Знайти кількість повних метрів у ньому." << endl;
    cout << "відстань у дециметрах = ";
    cin >> n;
    cout << "кількість повних метрів " << n / 10 << '\n' << endl;
    
    
    cout << "2.1. Дано двозначне число. Знайти: а) число десятків у ньому; б) число одиниць у ньому; в) суму його цифр; г) добуток його цифр. ";
    cin >> n;
    cout << "а) число десятків у ньому=" << n / 10 << '\t';
    cout << "б) число одиниць у ньому=" << n % 10 << '\t';
    cout << "в) суму його цифр=" << n / 10 + n % 10 << '\t';
    cout << "г) добуток його цифр=" << (n / 10) * (n % 10) << endl;

    cout << "2.2. Дано двозначне число. Отримати число, утворене при перестановці цифр заданого числа ";
    cin >> n;
    cout << "число, утворене при перестановці цифр=" << (n % 10) * 10 + (n / 10) << endl;

    cout << "2.3. Дано тризначне число. Знайти: а) число одиниць у ньому; б) число десятків у ньому; в) суму його цифр; г) добуток його цифр. ";
    cin >> n;
    cout << "а) число одиниць у ньому=" << n % 10 << '\t';
    cout << "б) число десятків у ньому=" << n % 100 / 10 << '\t';
    cout << "в) суму його цифр=" << (n / 100) + (n % 100 / 10) + (n % 100 % 10) << '\t';    
    cout << "г) добуток його цифр=" << (n / 100) * (n % 100 / 10) * (n % 100 % 10) << endl;

    cout << "2.4. Дано тризначне число. У ньому закреслили першу ліворуч цифру та приписали її наприкінці.Знайти полуденне число. ";
    cin >> n;
    cout << "отримане число = " << (n % 100) * 10 + n / 100 << endl;

    cout << "2.5. Дано тризначне число. У ньому закреслили останню праворуч цифру і приписали її на початку.Знайти отримане число. ";
    cin >> n;
    cout << "отримане число = " << (n % 10) * 100 + n / 10 << endl;

    cout << "2.6. Дано тризначне число. Знайти число, отримане під час перестановки першої та другої цифр заданого числа. ";
    cin >> n;
    cout << "отримане число = " << (n % 100 / 10) * 100 + (n / 100) * 10 + (n % 100 % 10) << endl;

    cout << "2.7. Дано тризначне число. Знайти число, отримане під час перестановки другої та третьої цифр заданого числа. ";
    cin >> n;
    cout << "потримане число = " << (n / 100) * 100 + (n % 100 % 10) * 10 + (n % 100 / 10) << endl;

    cout << "2.8. Дано трицифрове число, в якому всі цифри різні. Отримати шість чисел. утворених під час перестановки цифр заданого числа. ";
    cin >> n;
    r100 = (n / 100); // a
    r10 = (n % 100 / 10); // b
    r1 = (n % 100 % 10); // c
    cout << "вариант 1 = " << n << endl;
    cout << "вариант 2 = " << r100 * 100 + r1 * 10 + r10 << endl;
    cout << "вариант 3 = " << r10 * 100 + r100 * 10 + r1 << endl;
    cout << "вариант 4 = " << r10 * 100 + r1 * 10 + r100 << endl;
    cout << "вариант 5 = " << r1 * 100 + r100 * 10 + r10 << endl;
    cout << "вариант 6 = " << r1 * 100 + r10 * 10 + r100 << endl;

    cout << "2.9. Дано чотиризначне число. Знайти: а) суму його цифр; б) добуток його цифр. ";
    cin >> n;
    cout << "а) суму його цифр=" << (n / 1000) + (n % 1000 / 100) + (n % 1000 % 100 / 10) + (n % 1000 % 100 % 10) << endl;
    cout << "б) добуток його цифр=" << (n / 1000) * (n % 1000 / 100) * (n % 1000 % 100 / 10) * (n % 1000 % 100 % 10) << endl;

    cout << "2.10. Дано чотиризначне число. Знайти:\n";
    cout << "а) число, отримане під час прочитання його цифр праворуч наліво; \nб) число, що утворюється при перестановці першої та другої, третьої та четвертої цифр зданого числа" << endl;
    cin >> n;
    cout << "а) число, отримане під час прочитання його цифр праворуч наліво=" << (n % 1000 % 100 % 10) * 1000 + (n % 1000 % 100 / 10) * 100 + (n % 1000 / 100) * 10 + (n / 1000) << endl;
    cout << "б) число, що утворюється при перестановці першої та другої, третьої та четвертої цифр зданого числа=" << (n / 1000) * 100 + (n % 1000 / 100) * 1000 + (n % 1000 % 100 / 10) + (n % 1000 % 100 % 10) * 10 << endl;
    
    
    
    cout << "3.1. З тризначного числа х відняли його останню цифру. Коли результат розділили на 10, а до приватного зліва приписали останню цифру числам, то вийшло число 237. Знайти число х." << endl;
    cout << "число х=" << (237 % 100) * 10 + 237 / 100 << endl; //372

    cout << "3.2. У тризначному числі їх закреслили першу цифру. Коли число, що залишилося, помножили на 10, а добуток склали з першою цифрою числа х, то вийшло число 564. Знайти число х" << endl;
    cout << "число х=" << (564 / 10) + (564 % 10) * 100 << endl; // 456

    cout << "3.3. У тризначному числі їх закреслили першу цифру. Коли отримане число помножили на 10, а добуток склали з першою цифрою числа х, то вийшло число п. За заданим п знайти число х" << endl;
    cin >> n;
    cout << "число х=" << (n / 10) + (n % 10) * 100 << endl; //

    cout << "3.4. У тризначному числі їх закреслили його другу цифру. Коли до утвореного при цьому двозначного числа зліва приписали другу цифру числа х, то вийшло число 546. Знайти число х" << endl;
    cout << "число х=" << (546 / 100) * 10 + (546 % 100 / 10) * 100 + (546 % 100 % 10) << endl;

    cout << "3.5. У тризначному числі х закреслили його другу цифру Коли до утвореного при цьому двозначного числа зліва приписали другу цифру числа х, то вийшло число п. За заданим п знайти число х " << endl;
    cin >> n;
    cout << "число х=" << (n / 100) * 10 + (n % 100 / 10) * 100 + (n % 100 % 10) << endl;

    cout << "3.6. У тризначному числі їх закреслили його другу цифру. Коли до утвореного при цьому двозначного числа праворуч приписали другу цифру числа х, то вийшло число 456. Знайти число х" << endl;
    cout << "число х=" << (456 / 100) * 100 + (456 % 100 % 10) * 10 + (456 % 100 / 10) << endl; // 465

    cout << "3.7. У тризначному числі їх закреслили його другу цифру. Коли до утвореного при цьому двозначного числа праворуч приписали другу цифру числа х, то вийшло число n. За заданим п знайти число х" << endl;
    cin >> n;
    cout << "число х=" << (n / 100) * 100 + (n % 100 % 10) * 10 + (n % 100 / 10) << endl;

    cout << "3.8. У тризначному числі їх закреслили його останню цифру. Коли в двозначному числі, що залишилося, переставили цифри, а потім приписали до них зліва останню цифру числа х, то вийшло число 654. Знайти число х." << endl;
    cout << "число х=" << (654 / 100) + (654 % 100 / 10) * 10 + (654 % 100 % 10) * 100 << endl; // 456

    cout << "3.9. У тризначному числі їх закреслили його останню цифру. Коли в двозначному числі, що залишилося, переставили цифри, а потім приписали до них зліва останню цифру числа х, то вийшло число п.За заданим п знайти число х" << endl;
    cin >> n;
    cout << "число х=" << (n / 100) + (n % 100 / 10) * 10 + (n % 100 % 10) * 100 << endl;
    
    
    
    cout << "4.6. Наведено цілі числа h, т, s (0< h ≤ 23, 0≤ т≤ 59, 0≤ s ≤ 59), що вказують момент часу: ' h годин, т хвилин, s секунд'. Визначити кут(у градусах) між положенням годинникової стрілки на початку доби та у вказаний момент часу." << endl;
    cout << "H:m:s H-? ";
    cin >> n;
    n2 = n * (60 * 60);    
    cout << "H:m:s m-? ";
    cin >> n;
    n2 += (n * 60);
    cout << "H:m:s s-? ";
    cin >> n;
    n2 += n;    
    cout << "Кут стрілки " << (360.0 / (12 * 60 * 60)) * n2 << char(176);
    
    
    cout << "4.7. З початку доби годинна стрілка повернулася на у градусів (0 ≤ ≤ 360, у — речове число). Визначити кількість повних годин і кількість повних хвилин, що пройшли з початку доби. ";
    cin >> n;    
    n2 = n / (360.0 / (12 * 60)) * 60;
    cout << "на годиннику час " << n2 / (60 * 60) << ':' << n2 % (60 * 60) / 60;
    
    return 0;
    
}
