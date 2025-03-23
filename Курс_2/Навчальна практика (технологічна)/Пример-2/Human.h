#pragma once

#include <string>
#include <format>


using namespace std;

typedef unsigned short ushort;


class Human
{
	public:
		string name;
		ushort year;

		Human();
		Human(string name, ushort year);
		string ToString();
		ushort getAge(ushort yearNow);
};

