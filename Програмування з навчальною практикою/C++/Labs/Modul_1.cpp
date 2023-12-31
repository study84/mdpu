#include <windows.h> 
#include <iostream> 
  
using namespace std; 
  
int main() 
{ 
    SetConsoleOutputCP(1251); 

    //  1. Створити програму розрахунку функції
    int x; 
    cout << "введіть значення x="; 
    cin >> x; 
    int y{cos(pow(x, 2)) * sin(2 * x - 1) + 4.29}; 
    cout << "значение y" << y << endl; 

    
    // 2. Скласти і виконати програму, задавши вхідні дані самостійно. (2 бала) Ціни на два види товарів зросли на р відсотків. Вивести старі та нові ціни.
    double p, p1, p2; 
    cout << "вкажіть відсоток на який подорожчав товар  "; 
    cin >> p; 
    cout << "вкажіть нову (включно з % подорожчання) вартість 1го товару  "; 
    cin >> p1; 
    cout << "вкажіть нову (включно з % подорожчання) вартість 2го товару  "; 
    cin >> p2; 
    cout << "товар 1, який раніше коштував " << (p1 / (100 + p)) * 100 << " після здорожчання на " << p << "%, зараз коштує " << p1 << endl; 
    cout << "товар 2, який раніше коштував " << (p2 / (100 + p)) * 100 << " після здорожчання на " << p << "%, зараз коштує " << p2 << endl; 

    
    // 3. Трикутник  задано координатами вершин А(0;0), В(i;i-1) та С(-і,і+1), де і = номеру варіанта. Обчислити висоту hb  та медіану mc
    // Для вычисления длины отрезка на плоскости необходимо знать координаты двух точек, обозначим их (x1, y1) и (x2, y2). Затем можно использовать формулу длины отрезка в декартовой системе координат: d = sqrt((x2 — x1)^2 + (y2 — y1)^2), где d — длина отрезка.
    // https://ru.wikihow.com/найти-высоту-треугольника
     int triangle[][2] {{0,0}, {8, 7}, {-8, 9}}, ab{}, bc{}, ac{}, b; 
     
    ab = sqrt(pow(8 - 0, 2) + pow(7 - 0, 2)); 
    bc = sqrt(pow(-8 - 8, 2) + pow(9 - 7, 2)); 
    ac = sqrt(pow(-8 - 0, 2) + pow(9 - 0, 2)); 
    b = sqrt(pow(ab, 2) + pow(ac / 2, 2)); 
     
    cout << "висота=" << b << endl;
    
    
    // 5. Дано натуральне число. Знайти скільки разів у ньому зустрічається кожна цифра. (2 бала)
     cout << "введіть число, цифри якого ви хочете підрахувати "; 
    int num{}; 
    //int num = 453432546; 
    cin >> num; 
    int digits[10]{0}; 
    cout << digits[1] << endl; 
    int i; 
    while (num > 0) { 
        i = num % 10; 
        digits[i] += 1; 
        num /= 10; 
        //cout << num << '\t' << i << endl; 
    } 
  
    for (int d{ 0 }; d < 10; d++) 
        cout << d << '\t' << digits[d] << endl; 


    return 0;
}
