#pragma once
#include "Human.h"

//typedef unsigned short ushort;

class employee :
    private Human // �������� �� ������������ ----------------------------------------------------------------------------------
{
    public:
        float salaryH; // �� �� ������
        int workH; // �����

    public:
        employee();
        employee(string name, ushort year, float salary, int h);
        string ToString();
        float getSalaryMonth();
};

