#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    const int size = 5;
    
    int array[size];
    bool status{true};

    for (int i{ 0 }; i < size; i++) {
        cout << "Введіть елемент " << i + 1 << '\t';
        cin >> array[i];
    }
    cout << '\n' << endl;
    
    for (int i1{ 1 }; i1 < size; i1++) 
        if (array[i1 - 1] <= array[i1]) continue;
        else {
            status = false;
            break;
        }
    

    switch (status) {
    case true: cout << "УПОРЯДКОВАНИЙ" << endl; break;
    case false: cout << "НЕ УПОРЯДКОВАНИЙ" << endl; break;
    }
    
    
    return 0;
}
