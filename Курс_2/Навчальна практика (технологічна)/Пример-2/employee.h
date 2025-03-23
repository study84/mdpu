#pragma once
#include "Human.h"

//typedef unsigned short ushort;

class employee :
    private Human // УКАЗАНИЕ НА НАСЛЕДОВАНИЕ ----------------------------------------------------------------------------------
{
    public:
        float salaryH; // зп за годину
        int workH; // годин

    public:
        employee();
        employee(string name, ushort year, float salary, int h);
        string ToString();
        float getSalaryMonth();
};

