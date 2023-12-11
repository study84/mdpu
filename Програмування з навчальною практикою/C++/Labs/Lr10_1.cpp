#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    const int size = 16;    
    int array[size], min{}, max{}, imin{ 0 }, imax{ 0 };
    srand(time(NULL));

    for (int i{ 0 }; i < size; i++) {        
        array[i] = 1 + rand() % 50;
        cout << array[i] << " ";
    }
    cout << '\n' << endl;
    
    min = array[0];
    max = array[0];

    for (int i1{ 1 }; i1 < size; i1++) {        
        if (min > array[i1]) {
            imin = i1;
            min = array[i1];
        }
        
        if (max < array[i1]) {
            imax = i1;
            max = array[i1];
        }

    }
    cout << format("min={}\tindex_min={}\tmax={}\tindex_max={}", min, imin, max, imax);
    
    return 0;
}
