// Изучение C++ для начинающих / #12 – Указатели и ссылки
// https://www.youtube.com/watch?v=DKkAJtaE0w0&list=PLDyJYA6aTY1llzwya3FrWX4tmo-hm491p&index=13

#include <iostream>

using namespace std;

int main()
{
    // ссылки
    
    int num{10};
    int &n = num; // ссылка, содержит адрес оперативной памяти где содердится сама переменная, не может быть пустой!
    
    cout << &num << '\t' << num << endl;
    cout << &n << '\t' << n << endl;
    
    n = 15;
    
    cout << &num << '\t' << num << endl;
    cout << &n << '\t' << n << endl;
    
    cout << endl;
    
    // Указатели
    
    int val{12};
    int *ptrval{&val}; // указатель. может быть пустым, может выполнять сдвиг при работе с массивами. значения присваиваются через адрес ячейки в памяти
    
    cout << &val << '\t' << val << endl;
    cout << ptrval << '\t' << *ptrval << endl;
    
    ptrval = nullptr; // удалить значения указателя
    
    
    
    ///////////////////////////////
    
    srand(time(NULL));
    
    short s{10};
    
    short *arr = new short[s];
    
    for (size_t i{0}; i < s; i++) {
        arr[i] = 100 + rand() % 100;
        cout << i + 1 << '\t' << arr[i] << endl;
        
    }
    
   

    return 0;
}
