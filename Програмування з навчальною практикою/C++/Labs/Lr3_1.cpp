#include <iostream>
//#include <windows.h>
#include <cmath>

#define M_E 2.71828182845904523536

using namespace std;

int main() {
    //SetConsoleOutputCP(1251);
    
    double x{6.37}, a{2.56}, b{7.18};
    double y{};

    // 1
    y = cos(x - a) / (pow(M_E, x - a) + sqrt(abs(b * x)));
    cout << "1: " << y << endl;
    
    // 2
    y = (pow(M_E, abs(x-a))) / pow(cos(b * x), 2);
    cout << "2: " << y << endl;

    // 3
    y = (a * x + b) / (pow(log(b * x), 2) + sqrt(a));
    cout << "3: " << y << endl;

    // 4
    y = (3.1 * b - pow(M_E, a * x)) / (0.8 * pow(a * x, 3));
    cout << "4: " << y << endl;

    // 5    
    y = (atan(sqrt(b + x))) / (0.3 * pow(M_E, -a * x) - cos(b * x));
    cout << "5: " << y << endl;

    // 6
    y = (0.8 * cos(x + b)) / (sqrt(0.21 * x + a));
    cout << "6: " << y << endl;

    // 7
    y = (cos(a * x) + 5.87) / (sqrt(pow(b, 2) + pow(x, 3))); // v1
    //y = (cos(a * x) + 5.87) / (b + sqrt(pow(x, 3))); // v2
    cout << "7: " << y << endl;

    // 8
    y = sin(x - a * b) / (0.55 * pow(log(a * x + (b / x)), 2));
    cout << "8: " << y << endl;

    // 9
    y = (sqrt(a + x) + 0.25 * log(x)) / (x - 4.87);
    cout << "9: " << y << endl;

    // 10
    y = (pow(x, 3) + 5.8 * sin(a * b)) / (2.1 * x + 3 * a + b);
    cout << "10: " << y << endl;
    
    return 0;
}