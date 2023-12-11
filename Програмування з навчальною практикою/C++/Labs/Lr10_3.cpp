#include <windows.h>
#include <iostream>
#include <format>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);   

    const int size = 9;    
    int oct[size] = {}, dec[size];
    
    srand(time(NULL));
    
    for (int i{ 0 }; i < size; i++)
        oct[i] = rand() % 99;    
    
    cout << format("{:^}\t{:^}\t{:^}", "i", "OCT", "DEC") << endl;
    for (int i{ 0 }; i < size; i++) {
        int oct_numb{ oct[i] }, pow8{1}, calc{};
        while (oct_numb) {
            calc += (oct_numb % 10) * pow8;
            oct_numb /= 10;
            pow8 *= 8;
        }
        dec[i] = calc;
        cout << format("{}\t{}\t{}", i, oct[i], dec[i]) << endl;
    }    
    return 0;
}
