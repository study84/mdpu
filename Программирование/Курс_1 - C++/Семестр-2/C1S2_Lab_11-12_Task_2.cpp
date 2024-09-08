#include <iostream>
#include <string>
#include <format>

using namespace std;


struct DATE {
    // 8. Описати структуру «дата» (рік, місяць, день). Визначити функцію «днів до кінця року», яка обчислює кількість днів до кінця року
    string data;
    unsigned short year;
    unsigned short month;
    unsigned short day;
    unsigned short DaysBeforeYearEnd;
    bool lean_year;

    void func_LeanYear() {
        lean_year = !(year % 4);
        //cout << "Lean year: " << lean_year << endl;
    };

    int func_DaysBeforeYearEnd() {
        short days{ 365 };
        if (year % 4 == 0) days += 1;

        for (size_t m{ 1 }; m < month; m++) {
            switch (m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days -= 31; break;
            case 2:
                days -= 28; if (year % 4 == 0) days -= 1; break;
            case 4: case 6: case 9: case 11:
                days -= 30; break;
            }
        }

        days -= day;
        DaysBeforeYearEnd = days;
        //cout << days << endl;
        return days;
    }



};

int main()
{
    DATE test{};

    test.year = 2024;
    test.month = 3;
    test.day = 31;
    test.func_LeanYear();
    test.func_DaysBeforeYearEnd();

    cout << format("Year: {}\tMonth: {}\tDay: {}\tLean Year: {}\tDays Before Year-End: {}", test.year, test.month, test.day, test.lean_year, test.DaysBeforeYearEnd) << endl;


    return 0;
}
