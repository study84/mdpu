#include "Human.h"



Human::Human()
{
	name = "no name";
	year = 0;
}


Human::Human(string name, ushort year)
{
	this->name = name;
	this->year = year;
}

string Human::ToString()
{
	return format("Name: '{}', Year: {}", name, year);
}

ushort Human::getAge(ushort yearNow)
{	
	return yearNow < year ? 0: yearNow - this->year;
}
