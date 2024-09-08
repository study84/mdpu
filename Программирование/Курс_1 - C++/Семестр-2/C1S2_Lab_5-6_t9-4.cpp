#include <windows.h>
#include <iostream>
#include <format>
#include <string>
#include <iomanip>

using namespace std;

int* generate_array(short size);

int* fing_chain(int arr[], short size);


int main()
{
    SetConsoleOutputCP(1251);

    cout << "9 (Дуже складно) (Дуже складно) Напишіть функцію мовою C++, яка отримує цілочисельний масив та його розмір в якості аргументів і повертає новий масив, який містить найдовшу зростаючу підпослідовність вихідного масиву" << endl;
        
    int* arr = new int[] { 1, 2, 4, 6, 7, 4, 4, 6, 7, 5, 4, 6, 8, 9, 11, 12, 14 };
    fing_chain(arr, 17); // sizeof(arr) / sizeof(arr[0])
    
    short size{30};

    //cout << "введіть довжину масиву ";
    //cin >> size;    

    //int* arr = generate_array(size);    

    //fing_chain(arr, size);

    return 0;
}


int* generate_array(short size) {
    int* array = new int [size];
    cout << array << endl;
    srand(time(NULL));
    for (short i{ 0 }; i < size; i++) {
        *(array + i) = rand() / 100;
        cout << *(array + i) << ' ';
    }    
    cout << endl;
    return array;
}


int* fing_chain(int arr[], short size) {
    //int len1 = *(&arr + 1) - arr;
    //int len2 = sizeof(arr);
    //short len3 = sizeof(arr) / sizeof(int);
    //short len4 = sizeof(arr) / sizeof(arr[0]);
    //cout << endl << arr << format("\tlen1={}\tlen2={}\tlen3={}\tlen4={}", len1, len2, len3, len4) << endl;
    ////cout << *arr << '\t' << * (arr + len2) << endl;

    size_t count{ 0 }, best{ 0 }, first{ 0 }, end{ 0 };
    
    bool status{};

    for (size_t i{ 0 }; i < size; i++) { // size - 1
        //status = *(arr + i) <= *(arr + i + 1);
        if (i == size) status = true;
        else status = *(arr + i) <= *(arr + i + 1);
        //cout << format("i={}\t{}\ti+1={}\t{}\t{}\t{}\t{}\t{}\t{}", i, *(arr + i), i + 1, *(arr + i + 1), status, count, best, first, end) << endl;
        if (status) count++;        
        else {
            if (count > best) {
                best = count;
                first = i - count;
                end = i + 1;                
            }
            count = 0;
        }
    }
        
    cout << format("best={}\tfirst={}\tend={}", best, first, end) << endl;

    for (size_t i{ first }; i < end; i++) cout << arr[i] << '\t';

    delete[] arr;

    return 0;
}