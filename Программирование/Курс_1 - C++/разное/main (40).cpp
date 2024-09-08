// https://www.youtube.com/watch?v=DKkAJtaE0w0&list=PLDyJYA6aTY1llzwya3FrWX4tmo-hm491p&index=12

#include <iostream>

using namespace std;

void func(int* arr, int len) ;

int main()
{
    cout << "Ссылки" << endl;
    int a{10};
    int &aa{a}; // ссылка, обращается к адресу в памяти, не может быть пустой
    cout << &a << '\t' << a << endl;
    cout << &aa << '\t' << aa << endl;
    
    aa = 100;
    cout << &a << '\t' << a << endl;
    cout << &aa << '\t' << aa << endl;
    
    cout << endl;
    
    cout << "Указатели" << endl;
    int val{12};
    int* ptrval; // может быть пустой
    ptrval = &val;
    cout << "addrs" << '\t' << "value" << endl;
    cout << &val << '\t' << val << endl;
    cout << ptrval << '\t' << *ptrval << endl;
    
    *ptrval = 33;
    cout << &val << '\t' << val << endl;
    cout << ptrval << '\t' << *ptrval << endl;
    
    cout << "___" << endl;
    int arr[] = {1,2,3,4,5};
    func(arr, 5);

    return 0;
}



void func(int* arr, int len) {
    int min = *arr; // указатель на 1й элемент
    cout << min << endl;
    for (int i{1}; i < len; i++)
        cout << *(arr + i) << endl;
    
}



voidarr_din() {
    for (int i{1}; i < 5; i++){
    // int *array = new int[length]; // используем оператор new[] для выделения массива. Обратите внимание, переменная length не обязательно должна быть константой!
    int *arr = new int[i];
    1;
    //delete[] array; // используем оператор delete[] для освобождения выделенной массиву памяти
    delete[] arr;
    // arr[0] = 0;
   }
    
    
}