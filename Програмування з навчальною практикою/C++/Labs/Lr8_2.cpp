#include <windows.h>
#include <iostream>
#include <format>
#include <cmath>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    double x[]{ 7.3, 8.0, 9.25, 10.6, 10.3, 12.25, 43.0, 14.0 }, y[8]{}, min{}, max{};

    // розрахунок значень y
    for (int i{ 0 }; i < 8; i++) {
        y[i] = (2 * pow(x[i], 2) + 0.7) / (pow(log(0.8 * x[i]), 2) + sqrt(abs(pow(x[i], 2) - 8)));
        cout << format("{:^}\t{:>3.2f}\t{:>3.4f}", i, x[i], y[i]) << endl;
    }
    
    // пошук мін / макс
    min = y[0];
    max = y[0];    
    for (int i{ 1 }; i < 8; i++) {
        if (min > y[i]) min = y[i];
        if (max < y[i]) max = y[i];
    }

    cout << format("min={:>3.4f}\tmax={:>3.4f}", min, max) << endl;    
    
    return 0;
}
