#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    //Середній рівень
    
    int a{}, b{}, s1{}, s2{};
    double Body_Mass_Index{}, growth{};

    cout << "3 Перевірити, чи рік високосний (кратний 4) в межах від 2000 до нашої ери до 2000 нашої ери.Ввести з екрану рік та ознаку ери, вивести повідомлення у вигляді «656 рік нашої ери – високосний»." << endl;
    cout << "введіть рік (роки до нашої ери, вводяться як негативні) ";
    cin >> a;
    if (a % 4)
        cout << "рік " << a << " не високосний" << endl;
    else cout << "рік " << a << " високосний" << endl;
    
    cout << "4 Обчислити вартість покупки з урахуванням знижки. Знижка 10% надається, якщо сума купівлі перевищує 1000 гривень." << endl;
    cout << "введіть вартість покупки ";
    cin >> a;
    if (a > 1000)
        cout << "ваша покупка понад 1000, вам надається знижка 10%, з урахуванням знижки до оплати " << a * 0.9 << endl;
    else cout << "ваша покупка не превышает 1000, вам неполагается скидка, к оплате " << a << endl;
    
    cout << "5 Написати програму обчислення ідеальної ваги користувача (зростання 100).Видати рекомендації про необхідність погладшати або схуднути." << endl;
    cout << "введіть вашу вагу(кг) ";
    cin >> a;
    cout << endl;
    cout << "введіть ваш зріст(м) ";
    cin >> growth;
    cout << endl;
    Body_Mass_Index = a / (growth * growth);
    if (Body_Mass_Index < 16)
        cout << "Гострий дефіцит маси";
    else if (Body_Mass_Index >= 16 and Body_Mass_Index < 18.5)
        cout << "Недостатня маса тіла";
    else if (Body_Mass_Index >= 18.5 and Body_Mass_Index < 25)
        cout << "Норма";
    else if (Body_Mass_Index >= 25 and Body_Mass_Index < 30)
        cout << "Надлишкова маса тіла";
    else if (Body_Mass_Index >= 30 and Body_Mass_Index < 35)
        cout << "Ожиріння I ступеня";
    else if (Body_Mass_Index >= 35 and Body_Mass_Index < 40)
    cout << "Ожиріння II ступеня";
    else cout << "Ожиріння III ступеня";

    return 0;
}
