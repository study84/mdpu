#include <windows.h> 
#include <iostream>

using namespace std;

int main()

{
    SetConsoleOutputCP(1251);    
    
    int arr[4][4]{
        {1, 3, -8, 0},
        {-4, 6, 2, -5},
        {3, 7, 0, 6},
        {-3, 9, 11, -2}
    };

    for (int i{ 0 }; i < 4; i++) {
        for (int i1{0}; i1 < 4; i1++)
            cout << arr[i][i1] << '\t';
        
        cout << "\t||\t";
        for (int i1{ 0 }; i1 < 4; i1++) {
            if (arr[i][i1] > 0 and arr[i][i1] < 6) arr[i][i1] = 0;
            cout << arr[i][i1] << '\t';
        }
        cout << endl;
    }
    return 0;
}

