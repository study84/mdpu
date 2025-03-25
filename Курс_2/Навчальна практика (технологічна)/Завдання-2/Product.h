#pragma once

#include <string>
#include <format>
using namespace std;
typedef unsigned short ushort;
//typedef unsigned float ufloat;

class Product
{
	public:
		string name;
		float price;
		ushort amount;

	public:
		Product();
		Product(string name, float price, ushort amount);
		bool sufficient(ushort amount); // достатньо
		float total_cost();
		string info();
};

