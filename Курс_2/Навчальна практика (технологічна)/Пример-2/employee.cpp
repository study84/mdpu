#include "employee.h"

employee::employee()
{
	name = "employee";
	year = 0;
	salaryH = 0;
	workH = 0;
}

employee::employee(string name, ushort year, float salary, int h) : Human(name, year) // ��� ������������, ��� ������ �����������?
{
	salaryH = salary;
	workH = h;
}

string employee::ToString()
{
	return format("{}, Salary_month: {}", Human::ToString(), getSalaryMonth());
}

float employee::getSalaryMonth()
{
	return salaryH * workH;
}
