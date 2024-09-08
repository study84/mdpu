// ЛАБОРАТОРНА  РОБОТА №18
// варіант 8

#include <windows.h>
#include <iostream>
#include <format>
#include <string>

//#include <cmath>
//#include <utility>

//#include "func.h"

import Module;

using namespace std;

template <typename n, typename d>
n sqrt(n number, d degree);
//
//
template<typename F, typename S>
void decompose_pair(const pair<F, S>& p, F& first_val, S& second_val);



int main()
{
    SetConsoleOutputCP(1251);


    cout << "Завдання 1. Створити шаблон функції для обчислення кореня n-того ступеня з числа. Функція має працювати з числовими типами даних." << endl;
    //cout << xnmrt(8, 3) << endl;
    cout << sqrt(8.0, 3) << endl;
    cout << sqrt(8.0, 2.5) << endl; 
    cout << endl;


    cout << "Завдання 2. Декомпозиція пари:  Створіть  шаблонну  функцію, яка розбиває std::pair на дві змінні різного типу" << endl;
    pair<int, double> my_pair = make_pair(42, 3.14);
    int int_val;
    double double_val;
    decompose_pair(my_pair, int_val, double_val);
    cout << format("Перше значення: {}\tДруге значення: {}", int_val, double_val) << endl;
    
    pair<int, string> my_pair2 = make_pair(42, "pi");
    int int_val2;
    string double_val2;
    decompose_pair(my_pair2, int_val2, double_val2);
    cout << format("Перше значення: {}\tДруге значення: {}", int_val2, double_val2) << endl;
    cout << endl;


    cout << "Завдання 3. Створіть модуль, який містить конфігураційні налаштування (як константи), такі як максимальна кількість користувачів, шляхи файлів тощо.Використовуйте ці налаштування у вашій програмі" << endl;
    cout << endl;

    hello();
    cout << format("max_users={}\tuser_data_file={}\tlog_file={}", max_users, user_data_file, log_file) << endl;




    return 0;
}


template <typename n, typename d>
n sqrt(n number, d degree) {
    return pow(number, 1.0 / degree);
}


template<typename F, typename S>
void decompose_pair(const pair<F, S>& p, F& first_val, S& second_val) {
    first_val = p.first;
    second_val = p.second;
    ///[first_val, second_val] = p;
}