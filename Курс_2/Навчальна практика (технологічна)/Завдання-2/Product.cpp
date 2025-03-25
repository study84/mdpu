#include "Product.h"
#include <string>
#include <format>
using namespace std;
typedef unsigned short ushort;



Product::Product()
{
    this->name = "no name";
    this->price = 0;
    this->amount = 0;
}

Product::Product(string name, float price, ushort amount)
{
    this->name = name;
    this->price = price;
    this->amount = amount;
}

bool Product::sufficient(ushort amount)
//достатньо
{
    return this->amount >= amount;
}

float Product::total_cost()
{
    return this->price * this->amount;
}

string Product::info()
{
    return format("Name='{}', price={}, amount={}, total_cost={}", name, price, amount, total_cost());
}
