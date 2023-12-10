#include <iostream>
#include <windows.h>
#include <cmath>
#include <format>


#define M_E 2.71828182845904523536

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    double a{}, b{}, x{}, y{};
    
    cout << "вкажіть значення а "  << endl; cin >> a;
    cout << "вкажіть значення b " << endl; cin >> b;
    cout << "вкажіть значення x " << endl; cin >> x;
    cout << "вкажіть значення y " << endl; cin >> y;

    double formula[10]{};
    
    // 1
    formula[0] = 3 * pow(a, 2) * pow(x, 4) + a * pow(x, 2) + y;
    formula[1] = pow(M_E, x + y) + pow(M_E, x - y);
    formula[2] = abs(pow(x, 2) * sin(a * x) - pow(y, 3) * cos(a * x));
    formula[3] = 1 + pow(sin(a * x), 2) + pow(cos(a * y), 2);
    formula[4] = pow(tan(x / 2), 2);
    formula[5] = (cos(x) * tan(y)) / pow(M_E, a * x);
    formula[6] = log(formula[0] / formula[1]) + sqrt(formula[2] / formula[3]) - formula[4] + formula[5];
    cout << "1=" << formula[6] << endl;
    
    
    // 2
    formula[0] = sin(b * x) * tan(y / 2);
    formula[1] = b * pow(tan(x), 3) - 2 * pow(b, 2) * tan(x + 1);
    formula[2] = sin(x + y) + cos(x - y);
    formula[3] = 2 * pow(cos(b * x), 3);
    formula[4] = sqrt(pow(sin(y + 1), 2)) / (2 - cos(b * x));
    formula[5] = formula[0] - pow(formula[1] / formula[2], 1.0 / 3.0) + log(abs(formula[3] - formula[4]));
    cout << "2=" << formula[5] << endl;

    return 0;
}