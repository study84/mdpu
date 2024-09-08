#include <iostream>
#include <windows.h>
#include <cmath>

#define M_E 2.71828182845904523536

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    // Завдання 2.
    // варіант 15
    double x{}, y{};
    double array[][3] = {
        {3.5, -0.73, 2.5},
        {15.4, -5.6, 3.5},
        {5.1, 4, 2.7},
    };
    cout << "введіть значення x " << endl;
    cin >> x;
    for (int i{ 0 }; i < sizeof array / sizeof array[0]; i++) {
        //cout << array[i][0] << '\t' << array[i][1] << '\t' << array[i][2] << '\t' << endl;
        if (abs(1 - pow(x, 2)) == array[i][0] + array[i][2])
            y = sqrt(abs(array[i][0] * x - pow(cos(pow(array[i][1], 3) * x), 2) + 5.1 * pow(array[i][2], 2)));
        else if (abs(1 - pow(x, 2)) > array[i][0] + array[i][2])
            y = pow(M_E, pow(0.04, x)) + log(abs(pow(array[i][1], 5) * cos(x)));
        else if (abs(1 - pow(x, 2)) < array[i][0] + array[i][2])
            y = pow(pow(array[i][1], 2) * pow(x, 2), 2) + log(abs(array[i][1] * x - pow(array[i][0], 2)));
        cout << "a=" << array[i][0] << "\tb=" << array[i][1] << "\tc=" << array[i][2] << "\tx=" << x << "\ty=" << array[i][0] << endl;
    }

    return 0;
}
