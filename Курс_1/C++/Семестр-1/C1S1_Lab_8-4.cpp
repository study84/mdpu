#include <windows.h>
#include <iostream>
#include <format>
#include <cmath>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    const int size = 12;
    
    int array[size];
    int count3{ 0 };

    for (int i{ 0 }; i < size; i++) {
        cout << "Введіть елемент " << i + 1 << '\t';
        cin >> array[i];
    }
    cout << '\n' << endl;
    for (int i1{ 0 }; i1 < size; i1++) {
        cout << array[i1] << '\t';
        for (int i2{ i1 + 1 }; i2 < size; i2++) {
            //cout << format("i1={}\ta[i1]={}\ti2={}\ta[i2]={}\t{}", i1, array[i1], i2, array[i2], array[i1] + array[i2]) << endl;
            //cout << array[i1] << '\t' << array[i2] << endl;
            if ((array[i1] + array[i2]) % 3 == 0)
                count3++;
        }
    }
    cout << '\n' << endl;
    cout << "кількість парних елементів кратних 3 = " << count3;
    
    return 0;
}
