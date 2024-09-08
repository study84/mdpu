#include <windows.h>
#include <iostream>
#include <format>
#define M_E 2.71828182845904523536


using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    // cout << "Завдання 6.3" << endl;
    // const double pi{ 3.14159 }, d{0.001};
    // double s{};
    // int n{ 2 };
    // do {
    //     s += 1 / pow(n, 2);
    //     cout << s << endl;
    //     ++n;

    // } while (n < 100);

	
    cout << "Завдання 6.4 Скласти програму, що підраховує суму і добуток цілих чисел, що вводяться з клавіатури.При введенні числа 0 програма повинна вивести отримані значення суми і добутку на екран і закінчити роботу." << endl;
    int i{}, summation{0}, production{1};
    while (1) {
        cout << "введіть число (0 - завершення і виведення результату) " << endl;
        cin >> i;
        if (i) {
            summation += i;
            production *= i;
        }
        else break;	
    }
    cout << format("Сума={}\tДобуток={}", summation, production);

    cout << '\n' << endl;
    
    cout << "Завдання 6.5 Скласти програму, що виводить на екран таблицю значень тригонометричних функцій синус, косинус, тангенс і котангенс для кутів від 0˚ до 180? с кроком 10 ?" << endl;
    const double pi{3.14159};
    double s{}, c{}, t{}, ct{}, r{};
    cout << format("{:^3}\t{:^10}\t{:^10}\t{:^10}\t{:^10}\t{:^10}", char(176), "RAD", "Sin", "Cos", "Tg", "CTg") << endl;
    for (int g = 0; g <= 180; g += 10) {
        r = g * (pi / 180);
        s = sin(r);
        c = cos(r);
        t = tan(r);
        ct = atan(r);		
        cout << format("{:>3}\t{:10.4f}\t{:10.4f}\t{:10.4f}\t{:10.4f}\t{:10.4f}", g, r, s, c, t, ct) << endl;
    }
    
    return 0;
}
