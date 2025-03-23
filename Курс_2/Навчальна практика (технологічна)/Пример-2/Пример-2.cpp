// Пример-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

#include "employee.h"
#include "student.h";

using namespace std;



int main()
{
    employee emp("Serj", 2000, 25, 22 * 8);
    ///
    cout << emp.ToString() << endl;
    cout << emp.getSalaryMonth() << endl;

    student stu;
    cout << stu.ToString() << endl;
}
