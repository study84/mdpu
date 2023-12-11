#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    const int size = 11;    
    int arr[size] = {3, 9, -2, 8, 8, 6, -3, 6, -5, 11, 7}, sum{};
    
    //Ввести з клавіатури цілий масив, що складається з 11 елементів
    for (int i{ 0 }; i < size; i++) {
        cout << "Введіть елемент " << i + 1 << '\t';
        cin >> arr[i];
    }

    // Обчислити суму непарних за значенням від’ємних елементів (1, 3, 5...)
    for (int i{ 0 }; i < size; i += 2) {
        //cout << arr[i] << '\t';
        if (arr[i] < 0)
            sum += arr[i];
    }
    cout << endl;
    cout << "Обчислити суму непарних за значенням від’ємних елементів " << sum << endl;
    
    // замінити елементи кратні трьом на цю суму (arr[0] = 1, arr[1] = 2, arr[2] = 3 !, arr[5] = 3 !)
    for (int i{ 0 }; i < size; i++) {
        if ((i + 1) % 3 == 0)
            arr[i] = sum;
        cout << arr[i] << '\t';
    }
    
    return 0;
}
