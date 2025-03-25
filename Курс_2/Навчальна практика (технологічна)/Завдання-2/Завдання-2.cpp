// 513-і, Золотухін Андрій
// Завдання 2. Наслідування

#include <iostream>

#include "Product.h"
#include "Yogurt.h"

#include <format>

using namespace std;

typedef unsigned short ushort;



int main()
{
    setlocale(LC_ALL, "");
    
    Product prod;
    cout << prod.info() << endl;
    prod.price = 5.0f;
    prod.amount = 4;
    cout << prod.total_cost() << endl;
    cout << prod.sufficient(4) << endl;

    Product prod2("Milk product", 100, 1200);
    cout << prod2.info() << endl;    
    cout << prod2.total_cost() << endl;
    cout << prod2.sufficient(101) << endl;

    Yogurt yogurt;
    cout << yogurt.info() << endl;
    yogurt.setDate("2025-03-25");
    cout << format("1:\t{}", yogurt.info()) << endl;
    cout << yogurt.usable("2025-04-27") << endl;   

    Yogurt yogurt2("Yellow", "green", "2025-03-04");
    cout << format("2:\t{}", yogurt2.info()) << endl;

    Yogurt yogurt3("Yellow", 37, 10, "Milk+", "strawbery");
    cout << format("3:\t{}", yogurt3.info()) << endl;

    ////////////////////////////////////////////////////////

    const ushort size = 5;
    Yogurt yarr[size];

    ushort i{ 0 };
    string _date;

    while (size > i) {
        //cout << i << endl;
        cout << format("{} - Вкажіть бренд: ", i + 1);
        cin >> yarr[i].brand;
        cout << format("{} - Вкажіть смак: ", i + 1);
        cin >> yarr[i].flavor;
        cout << format("{} - Вкажіть кількість: ", i + 1);
        cin >> yarr[i].amount;
        cout << format("{} - Вкажіть ціна за 1: ", i + 1);
        cin >> yarr[i].price;
        cout << format("{} - Вкажіть термін придатності(YYYY-MM-DD): ", i + 1);
        cin >> _date;
        yarr[i].setDate(_date);
        i++;
    }
    
    cout << "Введіть дату для перевірки придатності йогурту(YYYY-MM-DD): ";
    cin >> _date;
    
    unsigned int max_total{ 0 }, maxs{ 0 };
    
    for (auto s{ 0 }; s < size; s++) {
        if(yarr[s].total_cost() > max_total) maxs = s;
        if (yarr[s].usable(_date)) cout << format("{}\t{}", s, yarr[s].info()) << endl;
    }
    cout << format("Йогурт із найбільшою сумарною вартістю: {}\t{}", maxs, yarr[maxs].info()) << endl;
    
}
