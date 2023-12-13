// Скласти програму, яка заповнює квадратну матрицю порядку n натуральними числами 1, 2, 3, .. ., n2, записуючи числа " по спіралі " за годинниковою стрілкою

#include <windows.h> 
#include <iostream>

using namespace std;

int main()

{
    SetConsoleOutputCP(1251);

    const int size = 5; // розмірність матриці(масиву)
    int arr[size][size];

    int value{0};
    int x{ 0 }, y{ 0 }; // координати старту
    char last{'r'}; // черодование пріоритету
    
    while (value < size * size) {
        value++;
        arr[x][y] = value;
        switch (last) {
        case 'r':
            if (arr[x][y + 1] < 0 and y + 1 < size) y++; // right
            else if (arr[x + 1][y] < 0 and x + 1 < size) x++; // down
            else if (arr[x][y - 1] < 0 and y > 0) y--; // left
            else if (arr[x - 1][y] < 0 and x > 0) { // up
                x--;
                last = 'u';
            }
            break;
        case 'u':
            if (arr[x - 1][y] < 0 and x > 0) x--; // up            
            else if (arr[x + 1][y] < 0 and x + 1 < size) x++; // down
            else if (arr[x][y - 1] < 0 and y > 0) y--; // left
            else if (arr[x][y + 1] < 0 and y + 1 < size) { // right
                y++;
                last = 'r';
            }
            break;        
        }        
    }

    for (int x{ 0 }; x < size; x++) {
        for (int y{ 0 }; y < size; y++)
            if (arr[x][y] < 0) cout << "." << '\t';
            else cout << arr[x][y] << '\t';
        cout << endl;
    }
    return 0;
}

