#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d;
    double x1, x2;
    
    cout << "введіть A ";
    cin >> a;
    cout << "введіть B ";
    cin >> b;
    cout << "введіть C ";
    cin >> c;
    
    if (a == 0) cout << "a = 0, немає рішення";
    else {
        d = b * b - 4 * a * c;
        
        if (d > 0) {
            x1 = (-b - sqrt(d)) / (2 * a);
            x2 = (-b + sqrt(d)) / (2 * a);
            cout << x1 << '\t' << x2 << endl;
        }
        else if (d == 0) {
            x1 = -b / (2 * a);
            cout << x1 << endl;
        }
        else
            cout << "немає рішення";
    }

    return 0;
}
