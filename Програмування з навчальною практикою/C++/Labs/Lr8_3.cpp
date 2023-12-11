#include <windows.h>
#include <iostream>
#include <format>
#include <cmath>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    double D[] = {5, -6, 24, -9.8, 15.3, 45, -6.23, 7, 2, -7, 54.1, 12.2, -23};
    
    double sum_a{}, sum_g{1};
    int count{};

    for (int i{ 0 }; i < 13; i++) {
        if (D[i] > 0) {
            sum_a += D[i];
            sum_g *= D[i];
            count++;
            cout << D[i] << '\t';
        }
    }    
    cout << endl;
    //cout << sum_a << endl;
    //cout << sum_g << endl;
    
    cout << "середнє арифметичне " << sum_a / count << endl;
    cout << "середнє геометричне " << pow(sum_g, 1.0 / count) << endl;    
    return 0;
}
