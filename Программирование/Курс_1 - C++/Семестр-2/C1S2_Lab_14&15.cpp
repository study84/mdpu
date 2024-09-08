// 823-і_Золотухін_Андрій_Олександрович

#include <windows.h>
#include <iostream>
#include <format>
#include <string>
#include <sstream> // Для std::istringstream

#include <stack>
#include <vector>


using namespace std;


short task1(string& input) { //"2 3 + 3 1 – *"
    stack<short> nums;
    short num1{ 0 }, num2{0};
    
    istringstream iss(input);

    auto digit = [](const string& str) {
        for (char c : str) if (!isdigit(c)) return false;
        return true;
    };

    while (iss >> input) {
        //cout << format("'{}'", input) << endl;
        //cout << format("'{}' = {}'", input, digit(input)) << endl;
        if (digit(input)) nums.push(stoi(input));
        else {
            num1 = nums.top();
            nums.pop();
            num2 = nums.top();
            nums.pop();
            
            switch (input[0])
            {
                case '+': nums.push(num2 + num1); break;
                case '-': nums.push(num2 - num1); break;
                case '*': nums.push(num2 * num1); break;
                case '/': nums.push(num2 / num1); break;
                default: break;
            }        
        }        
    }
    return nums.top();
}



string task2(string input) { // &
    istringstream iss(input);
    vector<int> nums;

    while (iss >> input) nums.push_back(stoi(input));

    short summ{ 0 };
    for (auto n : nums) if (n < 0 and (n % 2)) summ += n;
    for (auto& n : nums) if (!(n % 3)) n = summ;
    //for (auto n : nums) cout << n << '\t';

    stringstream ss;
    for (auto n : nums) ss << n << '\t';
    return ss.str();
}



string task3(const string& sequence) {
    stack<char> brackets;
    string message;
    for (auto s : sequence)
        switch (s)
        {
        case '(': case '[': case '{': brackets.push(s); break;
        case ')': case ']': case '}':
            if (!brackets.empty())
                if (brackets.top() == '(' and s == ')') brackets.pop();
                else if (brackets.top() == '[' and s == ']') brackets.pop();
                else if (brackets.top() == '{' and s == '}') brackets.pop();
                else {
                    return format("Відсутня відповідна пара {} != {}", brackets.top(), s);
                    //break;
                }
            else {
                return format("Відсутня відповідна пара для {}", s);
                //break;
            }
        default: break;
        }
    if (!brackets.empty()) {
        message = "Відсутня відповідна пара: ";
        for (auto p{ 0 }; !brackets.empty(); p++) {
            message += format("{}\t", brackets.top());
            brackets.pop();
        }
        message += '\n';
        return message;
    }
    else return format("Послідовність не має помилок");
    
}




int main()
{
    SetConsoleOutputCP(1251);
    cout << "Лабораторна робота 14-15\n" << endl;

    string input;    

    /*
    Завдання  1:  Арифметичний  вираз  можна  представити  у  зворотному польському записі, де знаки операції йдуть за операндами (а не ставляться між ними, як і в звичайному записі висловлювань). Зворотний польський запис не
    потребує дужок. Наприклад, виразу «1 + 2» відповідає запис «1 2 +», виразу «1 + 2 * 3» запис «1 2 3 * +» (спочатку множаться 2 на 3, а потім 1 складається з результатом), «(2 + 3) * (3 – 1)» записується як «2 3 + 3 1 – *».
    Задається рядок –  вираз  у  зворотному  польському  записі  (числа  та  знаки  +,  –,  *  розділені пробілами).  Використовуючи  стек,  обчисліть  значення  виразу.
    */
    cout << "Завдання 1. Введите задание для польского калькулятора: ";
    getline(cin, input);
    input = "2 3 + 3 1 - *";
    cout << format("Завдання 1: {}\n", task1(input)) << endl;

    
    /*
    Завдання 2(Варіант 8): Ввести з клавіатури цілий масив, що складається з 11 елементів. Обчислити суму непарних за значенням від’ємних елементів та замінити елементи кратні трьом на цю суму.  
    */    
    cout << "Завдання 2. Введіть числову послідовність: ";    
    getline(cin, input);
    // мають бути різні дані, парні позитивні, парні негативні, непарні позитивні, непарні негативні, деякі негативні та деякі позитивні парні 3
    input = "-6, 3, 8, -12, 15, -18, 21, -24, 27, -30, 4, -9, 10, -14, 17, -20, 22, -25, 28, -33";
    cout << format("Завдання 2: {}\n", task2(input)) << endl;    
    
    
    /*
    Завдання 3: Дана послідовність дужок виду "(", ")", "[", "]", "{", "}". Правильними скобочними послідовностями називається порожня послідовність, а також «(P)», «[P]», «{P}», де P – деяка правильна
    послідовність. Наприклад «{}()[]» і «{[][()()]}()» – правильні дужні послідовності, а «(]», «[()» та «({)}» – неправильні. Визначте чи є заданий
    рядок правильним скобковим виразом. Підказка: обробіть по черзі всі символи вхідного рядка, поміщаючи дужки, що відкривають, у стек, а для закриваючих
    дужок витягайте дужку зі стека і перевіряйте, чи відповідають вони один одному.
    */
    cout << "Завдання 3. Введіть послідовність дужок: ";
    getline(cin, input);
    string brackets[]{"()[]{}", "{[()]([{})}", "{[()([{}])]}{([]{}[()])}", "{[()([{}])]}{([]{}[()]})(({}))([]{}){[()([]{})]}{()[()]}", ")()[]{}"};
    input = brackets[4];    
    cout << format("Завдання 3: {}\n", task3(input)) << endl;

    //

    //stack<char> open;
    //stack<char> close;

    //for(auto b: brackets[1])
    //    switch (b)
    //    {
    //        case '(': case '[': case '{': open.push(b); break;
    //        case ')': case ']': case '}': close.push(b); break;    
    //    }

    //
    //for (; !open.empty();) {
    //    cout << format("{} - {}", open.top(), close.top()) << endl;
    //    open.pop();
    //    close.pop();
    //}
    //
    //for (; !close.empty();) {
    //    cout << format("{}", close.top()) << endl;        
    //    close.pop();
    //}

    ////////


    return 0;
}


