#include <iostream>

using namespace std;

int main()
{
    int a, b, ost, nod;
    
    cout << "Enter a: ";
    cin >> a;
    cout << endl;
    cout << "Enter b: ";
    cin >> b;
    
    if (a < b) swap(a, b);
    nod = b;
    
    cout << a << '\t' << b << '\n' << endl;
    
    while (true) {
        cout << a << '\t' << b << '\t';
        ost = a % b;
        cout << ost << endl;
        if (!ost) break;
        a = b;
        b = ost;
        nod = ost;
    }
    
    cout << nod;

    return 0;
}
