// 823-і Золотухін Андрій Олександрович
// МОДУЛЬ 2
// варіант 8

#include <windows.h>
#include <iostream>
#include <format>
#include <string>

#include <fstream>
#include <sstream>
#include <vector>
#include <stack>


using namespace std;


bool number_conversion(const string file_name) {
    ifstream file(file_name);

    if (!file.is_open()) {
        cout << "Помилка відкриття файлу!" << std::endl;
        return false;
    }

    auto binaryToHex = [](string num) {
        string num_c;        
        int num10{0};        
        for (int n = num.length(), level = 1; n > 0; n--, level *= 2)  if (num[n - 1] == '1') num10 += level;
        //cout << format("'{}'", num10);
        string symbols = "0123456789ABCDEF";
        string num16;
        while (num10 > 0) {
            int remainder = num10 % 16;
            num16.insert(0, 1, symbols[remainder]);
            num10 /= 16;
        }
        return num16;
    };

    string row;
    string num;
    while (getline(file, row)) {
        //cout << row << endl;
        istringstream iss(row);
        while (iss >> num)
            cout << format("{: <10}\t{}", num, binaryToHex(num)) << endl;
    }

    return true;
}






struct Car {
    const unsigned short production_year;
    const string brand;
    const string model;
    const string color;
    unsigned int mileage;
};

void infocar(vector<Car>& cars) {    
    unsigned int mileage{ cars[0].mileage };
    for (auto& c : cars) if (mileage > c.mileage) mileage = c.mileage;
    for (auto& c : cars) if (mileage == c.mileage) cout << format("Year: {}\t Brand: {}\tModel: {}\tColor: {}\tMileage: {}",
        c.production_year, c.brand, c.model, c.color, c.mileage) << endl;
}



string bracket_check(const string& me) {
    stack<char> brackets;
    //string message;
    for (auto s : me) {
        if (s == '(') brackets.push(s);
        else if (s == ')') {
            if (!brackets.empty() and brackets.top() == '(') brackets.pop();
            else return "Відсутня пара";
        }
    }
    if (brackets.empty()) return "Помилок не виявлено";
    else return "Відсутня пара";
}


int main()
{
    SetConsoleOutputCP(1251);


    cout << "Завдання 1. Створити програму, яка зчитує двійковий файл та виводить його вміст у вигляді шістнадцяткових чисел." << endl;
    number_conversion("numbers.txt");    
    
    
    cout << "Завдання 2. Написати функцію, яка приймає масив структур автомобілів і виводить інформацію про автомобіль з найменшим пробігом." << endl;
    vector<Car> cars{
        {2022, "Toyota", "Camry", "Blue", 10000},
        {2021, "Honda", "Accord", "Red", 15000},
        {2023, "Ford", "Mustang", "Yellow", 5000},
        {2020, "Chevrolet", "Malibu", "Silver", 20000},
        {2024, "BMW", "X5", "Black", 5000},
        {2019, "Mercedes-Benz", "C-Class", "White", 25000},
        {2022, "Audi", "A4", "Gray", 12000},
        {2021, "Nissan", "Altima", "Green", 18000},
        {2023, "Hyundai", "Elantra", "Orange", 7000},
        {2020, "Kia", "Optima", "Purple", 30000}
    };

    infocar(cars);
    cout << endl;


    cout << "Завдання 3. Написати програму, яка використовує std::stack для перевірки правильності розстановки дужок у математичному виразі" << endl;
    string math_expression = "((3×(4+7))−((5×2)+(8−3)))+(((6−2)×(9+1))−(4×(7−2)))";
    math_expression = "((3×(4+7))−((5×2)+(8−3)))+(((6−2)×(9+1))−(4×(7−2)))";
    cout << bracket_check(math_expression) << endl;

    return 0;
}


