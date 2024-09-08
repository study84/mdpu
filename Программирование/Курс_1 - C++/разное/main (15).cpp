#include <iostream>
#include <string>
using namespace std;

void* func() {
    string text{"Hello"};
    bool flag = true;
    int number = 42;
    
    // Массив указателей на различные типы данных
    void* addresses[3];
    addresses[0] = &text;
    addresses[1] = &flag;
    addresses[2] = &number;

    // Printing addresses
    for (int i = 0; i < 3; ++i) {
        cout << "Address " << i << ": " << addresses[i] << endl;
    }
    
    return addresses;
}

int main() {
    void* result = func();
    // Do something with the result
    //cout << result << endl;
    for (size_t r{0}; r < 3; r++)
        cout << result + r << endl;
    
    
    return 0;
}
