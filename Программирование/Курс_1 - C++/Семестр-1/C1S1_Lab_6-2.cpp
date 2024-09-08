#include <windows.h>
#include <iostream>
#include <format>
#define M_E 2.71828182845904523536


using namespace std;
int main()
{
    double xn{}, xk{}, dx{}, a{}, b{}, y{};
    
    cout << "3" << endl;
    xn=4.5, xk=48, dx=5.2, a=2.8, b=0.015, y=0;
    cout << format("xn={:5.3f}\txk={:5.3f}\tdx={:5.3f}\ta={:5.3f}\tb={:5.3f}", xn, xk, dx, a, b) << endl;
    for (double x = xn; x < xk; x += dx) {
        if (log(x) > a) {
            y = sqrt(pow(a, 2) + x) / (pow(M_E, b * x) - a);
            cout << format("xn = {:6.2f}\ty = {:6.2f}", x, y) << endl;
        }
        else {
            y = sqrt(pow(log(x), 5) + pow(log(a), 3));
            cout << format("xn = {:6.2f}\ty = {:6.2f}", x, y) << endl;
        }			
    }

    cout << endl;
    
    cout << "3" << endl;
    xn=1.83, xk=17.74, dx=2.1, a=2.25, b=0.86, y=0;
    cout << format("xn={:5.3f}\txk={:5.3f}\tdx={:5.3f}\ta={:5.3f}\tb={:5.3f}", xn, xk, dx, a, b) << endl;
    for (double x = xn; x < xk; x += dx) {
        if (log(x) > a) {
            y = pow(a + b * x, 1.0 / 4.0) / pow(log(x), 2);
            cout << format("xn = {:6.4f}\ty = {:6.4f}", x, y) << endl;
            }
        else {
            y = pow(a, 2) * pow(M_E, -b * x);
            cout << format("xn = {:6.4f}\ty = {:6.4f}", x, y) << endl;
        }
    }
    return 0;
}
