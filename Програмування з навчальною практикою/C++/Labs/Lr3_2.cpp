#include <iostream>
#include <windows.h>
#include <cmath>
#include <format>


#define M_E 2.71828182845904523536

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    double x{ 2.28 }, a{ 3.56 }, b{ 5.86 };
    double y1{}, y2{};

    cout << format("{:>3}\t{:^8}\t{:^8}", "#", "y1", "y2") << endl;
    
    // 1
    y1 = pow(x, 3) - (3 * pow(x, 2) * a) + (3 * x * pow(a, 2)) - pow(a, 3);
    y2 = pow(M_E, x - a) / cos(b * x);
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 1, y1, y2) << endl;

    // 2
    y1 = a * pow(log(b * x), 2);
    y2 = pow((a * x + b) / tan(0.25 * b * x), 1.0 / 3.0);
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 2, y1, y2) << endl;

    // 3
    y1 = pow(cos(a * x), 3);
    y2 = pow(log(b * x - a), 2) / pow(M_E, -(x / b));
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 3, y1, y2) << endl;

    // 4
    y1 = pow(sin(b + x), 3);
    y2 = (log(x) + cos(5 * a * b)) / (pow(b * x, 3) - pow(a, 2));
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 4, y1, y2) << endl;

    // 5
    y1 = pow(pow(x, 3) + pow(a, 3), 1.0 / 5.0);
    y2 = pow(sin(a * x), 2) / tan(pow(x, 2) - b);
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 5, y1, y2) << endl;

    // 6
    y1 = sqrt(a + pow(log(x), 2));
    y2 = (sin(x) + sqrt(a * b)) / atan(b - x);
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 6, y1, y2) << endl;

    // 7
    y1 = (pow(a, 2) * (1 / pow(M_E, b * x)));
    y2 = pow(a + b * x, 1.0 / 5.0) / pow(log(x), 2);
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 7, y1, y2) << endl;

    // 8
    y1 = pow(M_E, a * x) + pow(x, 1.0 / 3.0);
    y2 = (2 * a * x - b) / (pow(b, 2) + pow(x, 4));
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 8, y1, y2) << endl;

    // 9 
    y1 = atan(b * x - a * pow(M_E, x - b));
    y2 = (b * pow(sin(a * x), 2)) / pow(abs(b * x - a), 1.0 / 3.0);
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 9, y1, y2) << endl;

    // 10 
    y1 = pow(a, 3) + pow(cos(b * x), 2);
    y2 = (pow(x, a) + 20.5 * pow(a, 3) * b) / atan(a * x + abs(b - pow(a, 2)));
    cout << format("{:>3}\t{:>8.4f}\t{:>8.4f}", 10, y1, y2) << endl;

    return 0;
}