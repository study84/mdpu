#include <iostream>

using namespace std;

int main()
{
    int m{4}, d{29}, old{39}, calc;
    
    calc = m * 100;
    cout << calc << endl;
    
    calc += d;
    cout << calc << endl;
    
    calc *= 2;
    cout << calc << endl;
    
    calc += 8;
    cout << calc << endl;
    
    calc *= 5;
    cout << calc << endl;
    
    calc += 4;
    cout << calc << endl;
    
    calc *= 10;
    cout << calc << endl;
    
    calc += 4;
    cout << calc << endl;
    
    calc += old;
    cout << calc << endl;
    
    calc -= 444;
    cout << calc << endl;

    return 0;
}
