#include <windows.h>
#include <iostream>
#include <format>
#define M_E 2.71828182845904523536


using namespace std;
int main()
{
    double xn{}, xk{}, dx{}, a{}, b{}, y{};
    
    cout << "1" << endl;
    xn = 5.8, xk=17, dx=1.2, a=1.7, b=0.36, y=0;
    cout << format("xn={:5.3f}, xk={:5.3f}, dx={:5.3f}, a={:5.3f}, b={:5.3f}, formula: y = sin(x - a) / (pow(M_E, a - x) + sqrt(abs(b * x)))", xn, xk, dx, a, b) << endl;
    for (double x = xn; x < xk; x += dx) {
        y = sin(x - a) / (pow(M_E, a - x) + sqrt(abs(b * x)));
        cout << format("xn = {:6.2f}\ty = {:6.2f}", x, y) << endl;
    }

    cout << endl;

    cout << "5" << endl;
    xn=3.1, xk=9.3, dx=0.65, a=4.38, b=0.4, y=0;
    cout << format("xn={:5.3f}, xk={:5.3f}, dx={:5.3f}, a={:5.3f}, b={:5.3f}, formula: atan(sqrt(b + x)) / (0.3 * pow(M_E, -a * x) - sin(a * x))", xn, xk, dx, a, b) << endl;
    for (double x = xn; x < xk; x += dx) {
        y = atan(sqrt(b + x)) / (0.3 * pow(M_E, -a * x) - sin(a * x));
        cout << format("xn = {:6.2f}\ty = {:6.2f}", x, y) << endl;
    }

    cout << endl;

    cout << "6" << endl;
    xn=5, xk=16, dx=1.2, a=1.5, b=14.8, y=0;
    cout << format("xn={:5.3f}, xk={:5.3f}, dx={:5.3f}, a={:5.3f}, b={:5.3f}, formula: y = 0.3 * cos(x + b) / (pow(0.34 * x + a * b, 1.0 / 3.0))", xn, xk, dx, a, b) << endl;
    for (double x = xn; x < xk; x += dx) {
        y = 0.3 * cos(x + b) / (pow(0.34 * x + a * b, 1.0 / 3.0));
        cout << format("xn = {:6.2f}\ty = {:6.2f}", x, y) << endl;
    }

    return 0;
}
