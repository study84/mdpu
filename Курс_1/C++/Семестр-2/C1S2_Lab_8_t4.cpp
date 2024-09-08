#include <windows.h>
#include <iostream>
#include <format>
#include <string>
//#include <iomanip>

using namespace std;


int nod_test(int a, int b);
int nod(int a, int b);


int main()
{
    SetConsoleOutputCP(1251);

    cout << "Варіант 8" << endl;
    cout << "Напишіть функцію на мові C++ для знаходження НСД(найбільшого спільного дільника) двох чисел з використанням рекурсії, яка отримує на вхід два посилання і повертає результат у вигляді посилання" << endl;
    
    /*cout << nod_test(330, 495) << endl;
    cout << endl;
    int at{ 330 }, bt{ 495 }, & aa{ at }, & bb{ bt };
    cout << nod(aa, bb) << endl;*/


    int a{}, b{}, & aa{ a }, & bb{ b };

    cout << "Введіть перше число ";
    cin >> a;

    cout << "Введіть друге число ";
    cin >> b;

    cout << format("для {} и {} НСД={}", a, b, nod(aa, bb)) << endl;

    return 0;
}


int nod_test(int a, int b) {
    if (b > a) swap(a, b);    
    int n{ a % b };
    //cout << format("{}:{}={}", a, b, n) << endl;
    if (n) nod_test(b, n);
    else return b;
}


int nod(int a, int b) {
    if (b > a) swap(a, b);
    int n{ a % b };
    int& nn{ n };
    cout << format("{}:{}={}", a, b, nn) << endl;
    if (nn) nod(b, nn);
    else return b;
}