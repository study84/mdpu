#include "Yogurt.h"
#include <chrono>
#include <regex>

//#include <iostream>
//using namespace std;


Yogurt::Yogurt()
{
    this->brand = "новинка";
    this->flavor = "без наповнювача, без цукру";
    ///
    tm date1900 = { 0, 0, 0, 1, 0, 1900 - 1900 };
    time_t time1900 = std::mktime(&date1900);
    time_t currentTime = std::time(nullptr);
    double seconds = std::difftime(currentTime, time1900);
    ushort days = static_cast<ushort>(seconds / (60 * 60 * 24));
    this->expiration_date = days + 14;
}

Yogurt::Yogurt(string brand, string flavor, string date) //: Product(name, price, amount)

{
    this->brand = brand;
    this->flavor = flavor;
    this->expiration_date = date_convert(date);
}

Yogurt::Yogurt(string name, float price, ushort amount, string brand, string flavor, string date) : Product(name, price, amount)
{
    this->brand = brand;
    this->flavor = flavor;
    this->expiration_date = date_convert(date);
}

bool Yogurt::setDate(string date)
{
    if (validator(date)) {
        this->expiration_date = date_convert(date);
        return true;
    }    
    return false;
}

string Yogurt::getDate()
{
    return date_convert(this->expiration_date);
}

string Yogurt::info()
{
    return format("{}, brand='{}', flavor='{}', expiration_date='{}'", Product::info(), brand, flavor, date_convert(this->expiration_date));
}

bool Yogurt::usable(string date)
{
    //cout << this->expiration_date << '\t' << date_convert(date) << endl;
    if (validator(date)) return this->expiration_date >= date_convert(date);
    return false;
}

bool Yogurt::isLeapYear(const ushort year) {
    // рік високосний: y-true / n-false
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool Yogurt::validator(const string str)
{
    static const regex pattern_date("\\b(19[0-9][0-9]|20[0-9][0-9])-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])\\b");
    return regex_match(str, pattern_date);
}

ushort Yogurt::date_convert(const string date)
{
    ushort days{ 0 };    

    if (validator(date)) {
        ushort year, month, day;
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        for (short y{ 1900 }; y < year; y++)
            days += (Yogurt::isLeapYear(y) ? 366 : 365);

        for (short m{ 1 }; m < month; m++) {
            switch (m)
            {
            case 2: days += (Yogurt::isLeapYear(year) ? 29 : 28); break;
            case 4: case 6: case 9: case 11: days += 30; break;
            default: days += 31; break;
            }
        }

        days += day;
    
    }
    
    return days;
}

string Yogurt::date_convert(ushort days) {
    // перетворення дати з кількість днів з 1900-01-01 у дату рядок
    string date{ "NO DATA" };
    ushort d[]{ 1900, 1, 1 };

    while (days >= (366 - !isLeapYear(d[0]))) {
        days -= (366 - !isLeapYear(d[0]));
        d[0] += 1;
    }

    int months_days[]{ 31, (29 - !isLeapYear(d[0])), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    short month{ 0 };
    while (days >= months_days[month]) {
        days -= months_days[month];
        d[1]++;
        month++;
    }

    d[2] += days;

    date = format("{}-{:0>2}-{:0>2}", d[0], d[1], d[2]);
    return validator(date) ? date : format("{} - невірний формат дати!", date);
}