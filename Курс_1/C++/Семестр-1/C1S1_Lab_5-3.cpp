#include <iostream>
#include <windows.h>
#include <cmath>

#define M_E 2.71828182845904523536

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    cout << "1. Написати програму, яка за кодом міста і тривалості переговорів обчислює їх вартість і результат виводить на екран : Одеса - код 048, 15 грн; Київ - код 044, 18 грн; Харків - код 046, 13грн; Вінниця - код 045, 11г" << endl;
    int city{}, duration{};
    cout << "вкажіть код міста ";
    cin >> city; // отримання коду міста
    cout << "вкажіть тривалість розмови в хвилин ";
    cin >> duration; // отримання коду міста
    // визначення міста за вказаним кодом, розрахунок вартості дзвінка
    switch (city) {
    case 48: cout << "зазначеному коду 0" << city << " відповідає місту Одеса, з тарифом 15 грн, загальна вартість дзвінка " << duration * 15 << "грн" << endl; break;
    case 44: cout << "зазначеному коду 0" << city << " відповідає місту Київ, з тарифом 18 грн, загальна вартість дзвінка " << duration * 18 << "грн" << endl; break;
    case 46: cout << "зазначеному коду 0" << city << " відповідає місту Харків, з тарифом 13 грн, загальна вартість дзвінка " << duration * 13 << "грн" << endl; break;
    case 45: cout << "зазначеному коду 0" << city << " відповідає місту Вінниця, з тарифом 11 грн, загальна вартість дзвінка " << duration * 11 << "грн" << endl; break;
    }

    cout << "------------------------------------------" << endl;

    cout << "4. Написати програму, яка за датою народження (день d місяць n) визначає знак Зодіаку..." << endl;
    int day{}, month{};

    cout << "введіть місяць, коли ви народилися ";
    cin >> month;
    cout << "введіть число, коли ви народилися ";
    cin >> day;
    switch (month) {
    case 1:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Козеріг" << endl; else cout << "Водолій" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 2:
        if (1 <= day and day <= 29) if (day <= 21) cout << "Водолій" << endl; else cout << "Риби" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 3:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Риби" << endl; else cout << "Овен" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 4:
        if (1 <= day and day <= 30) if (day <= 21) cout << "Овен" << endl; else cout << "Телець" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 5:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Телець" << endl; else cout << "Близнюки" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 6:
        if (1 <= day and day <= 30) if (day <= 21) cout << "Близнюки" << endl; else cout << "Рак" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 7:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Рак" << endl; else cout << "Лев" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 8:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Лев" << endl; else cout << "Діва" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 9:
        if (1 <= day and day <= 30) if (day <= 21) cout << "Діва" << endl; else cout << "Ваги" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 10:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Ваги" << endl; else cout << "Скорпіон" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 11:
        if (1 <= day and day <= 30) if (day <= 21) cout << "Скорпіон" << endl; else cout << "Стрілець" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    case 12:
        if (1 <= day and day <= 31) if (day <= 21) cout << "Стрілець" << endl; else cout << "Козеріг" << endl;
        else cout << "для меяца " << month << " немає дня " << day << endl;
        break;
    default: cout << "ввели неіснуючий номер місяця, їх усього 12 !" << endl; break;
    }

    return 0;
}
