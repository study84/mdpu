#include <windows.h>
#include <iostream>
#include <format>
//#include <string>
//#include <iomanip>

using namespace std;

void count_occurrences();
int count_occurrences(int* arr, size_t size, int key);
int count_occurrences(double* arr, size_t size, double key);

bool array_gen(int* arr, size_t size);
bool array_gen(double* arr, size_t size);


int main()
{
    SetConsoleOutputCP(1251);

    cout << "Варіант 8" << endl;

    cout << "1: Створіть програму C++, яка містить функцію під назвою 'count_occurrences', яка приймає масив цілих чисел і ключ пошуку та повертає кількість входжень ключа пошуку в масиві. Перевантажте цю функцію, щоб прийняти масив із числами з плаваючою точкою та ключ пошуку та повернути кількість входжень ключа пошуку в масиві" << endl;
    count_occurrences();

    return 0;
}


void count_occurrences() {
    size_t size;
    cout << "Введіть розмір масиву: ";
    cin >> size;


    char arr_type;
    cout << "тип даних int(I/i) / double(D/d): ";
    cin >> arr_type;


    if (arr_type == 'I' or arr_type == 'i') {
        int* array = new int[size];
        //cout << array;
        if (array_gen(array, size)) {            
            //for (size_t a{ 0 }; a < size; a++) cout << array[a] << '\t';            
            int key;
            cout << "Яке значення будемо шукати? ";
            cin >> key;
            cout << format("{} знайдено {} раз", key, count_occurrences(array, size, key)) << endl;
        }
        delete[] array;
    }

    else if (arr_type == 'D' or arr_type == 'd') {
        double* array = new double[size];        
        //cout << array << endl;
        //int array_{ *array };
        if (array_gen(array, size)) {            
            //for (size_t a{ 0 }; a < size; a++) cout << array[a] << '\t';            
            double key;
            cout << "Яке значення будемо шукати? ";
            cin >> key;
            cout << format("{} знайдено {} раз", key, count_occurrences(array, size, key)) << endl;
        }
        delete[] array;
    }    
}


bool array_gen(int* arr, size_t size) {    
    char arr_gen{ 'y' };
    cout << "Автоматично генерувати масив (Y/n): ";
    cin >> arr_gen;
    if (arr_gen == 'Y' or arr_gen == 'y') {
        srand(time(NULL));
        int min{1}, max{0};
        while (min > max) {
            cout << "Мінімальне значення: ";
            cin >> min;
            cout << "Максимальне значення: ";
            cin >> max;
        }
        max--;
                
        auto rnd = [](int min, int max) {return (rand() % (max - min + 1) + min) + ((rand() % 100) * 0.01); }; //round(1.87877, 2);

        for (size_t a{ 0 }; a < size; a++) arr[a] = rnd(min, max);
        //for (size_t a{ 0 }; a < size; a++) cout << format("({}:{})\t", a, arr[a]) << endl;
        return true;
    }
    else if (arr_gen == 'N' or arr_gen == 'n') {
        for (size_t a{ 0 }; a < size; a++) {
            cout << a + 1 << '\t';
            cin >> arr[a];
        }
        return true;            
    }
    return false;
}


bool array_gen(double* arr, size_t size) {
    char arr_gen{ 'y' };
    cout << "Автоматично генерувати масив (Y/n): ";
    cin >> arr_gen;
    if (arr_gen == 'Y' or arr_gen == 'y') {
        srand(time(NULL));
        int min{ 1 }, max{ 0 };
        while (min > max) {
            cout << "Мінімальне значення: ";
            cin >> min;
            cout << "Максимальне значення: ";
            cin >> max;
        }
        max--;

        auto rnd = [](int min, int max) {return (rand() % (max - min + 1) + min) + ((rand() % 100) * 0.01); }; //round(1.87877, 2);

        for (size_t a{ 0 }; a < size; a++) arr[a] = rnd(min, max);
        //for (size_t a{ 0 }; a < size; a++) cout << format("({}:{})\t", a, arr[a]) << endl;
        return true;
    }
    else if (arr_gen == 'N' or arr_gen == 'n') {
        for (size_t a{ 0 }; a < size; a++) {
            cout << a + 1 << '\t';
            cin >> arr[a];
        }
        return true;
    }
    return false;
}


int count_occurrences(int* arr, size_t size, int key) {
    short count{ 0 };
    for (size_t a{ 0 }; a < size; a++)
        if (arr[a] == key) count++;

    return count;    
}


int count_occurrences(double* arr, size_t size, double key) {
    short count{ 0 };
    for (size_t a{ 0 }; a < size; a++)
        if (arr[a] == key) count++;

    return count;
}


//template <typename data>
//int count_occurrences(data* arr, size_t size, data key) {
//    short count{ 0 };
//    for (size_t a{ 0 }; a < size; a++)
//        if (arr[a] == key) count++;
//
//    return count;
//}