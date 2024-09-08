// Задана квадратна матриця розміром N×N (N<=10), що складається з дійсних чисел. Знайти добуток найменших елементів кожного стовпця матриці.

#include <windows.h> 
#include <iostream>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
	
	const int size{10};
    int calc{1}, min;
    srand(time(NULL));
    
    int arr[size][size];
    
    for (int i{0}; i < size; i++) {
        for (int i1{0}; i1 < size; i1++) {
            arr[i][i1] = rand() % 100;
            cout << arr[i][i1] << '\t';
        }
        cout << endl;
    }
    
    cout << endl;
    
    for (int i{0}; i < size; i++) {
        min = arr[0][i];
        for (int i1{1}; i1 < size; i1++)
            if (arr[i1][i] < min) min = arr[i1][i];
        calc *= min;
        cout << min << '\t';
    }
    cout << endl;
    cout << "Добуток=" << calc << endl;

    return 0;
}
