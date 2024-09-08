#include <windows.h>  
#include <iostream> 

using namespace std; 

int main() 
{ 
    SetConsoleOutputCP(1251);     

    int arr[4][4]{ 
        {4, 8, 11, 5}, 
        {2, 12, 9, 14}, 
        {0, 5, 0, 7}, 
        {1, 6, 3, 4} 
    }; 

    for (int i{ 0 }; i < 4; i++) { 
        for (int i1{0}; i1 < 4; i1++) 
            cout << arr[i][i1] << '\t'; 
        cout << endl; 
    } 


    cout << endl; 
    cout << "Обміняти місцями нульовий і третій рядки" << endl; 

    for (int i{ 0 }; i < 4; i++) 
        swap(arr[0][i], arr[3][i]); 

    for (int i{ 0 }; i < 4; i++) { 
        for (int i1{ 0 }; i1 < 4; i1++) 
            cout << arr[i][i1] << '\t'; 
        cout << endl; 
    } 

    cout << endl; 
    cout << "Обміняти місцями перший і третій стовпці." << endl; 

    for (int i{ 0 }; i < 4; i++) 
        swap(arr[i][1], arr[i][3]); 

    for (int i{ 0 }; i < 4; i++) { 
        for (int i1{ 0 }; i1 < 4; i1++) 
            cout << arr[i][i1] << '\t'; 
        cout << endl; 
    } 
    return 0; 
} 