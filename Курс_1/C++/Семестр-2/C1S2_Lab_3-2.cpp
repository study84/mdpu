#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    string txt{};
    //getline(cin, txt);
    size_t index{};
    
    
    // 1. В заданому рядку замінити послідовні пробіли на один пробіл
    txt = "     abc  def   123            ";
    while (txt[0] == ' ') txt.erase(0, 1);
    while (txt[txt.length() - 1] == ' ') txt.erase(txt.length() - 1, 1);
    index = 0;
    while ((index = txt.find("  ")) != string::npos) txt.erase(index, 1);
    cout << "1. В заданому рядку замінити послідовні пробіли на один пробіл\t" << '\'' << txt << '\'' << endl;


    // 2. В заданому рядку підрахувати кількість слів. Роздільником слів вважається один або кілька пробілів
    txt = " abc  def   123 j jsd u uiu asd sad uxyczc  ";
    index = 0;
    size_t words{ 0 };
    while (txt[0] == ' ') txt.erase(0, 1);
    while (txt[txt.length() - 1] == ' ') txt.erase(txt.length() - 1, 1);
    while (index != string::npos) {        
        index = txt.find_first_not_of(' ', index);
        words += 1;
        index = txt.find_first_of(' ', index);        
    }    
    cout << "2. В заданому рядку підрахувати кількість слів. Роздільником слів вважається один або кілька пробілів\t" << words << endl;


    // 3. В заданому рядку видалити всі латинські літери
    txt = "yxufsгнчгвuyxdsuвыгнвыuyfdfuysгвывг";
    index = 0;
    while ((index = txt.find_first_of("abcdefghijklmnopqrstuvwxyz")) != string::npos) txt.erase(index, 1);
    cout << "3. В заданому рядку видалити всі латинські літери\t" << txt << endl;


    // 4. Дано рядок. Дописати в кінець рядка його довжину
    txt = " abc  def   123 j jsd u uiu asd sad uxyczc  ";
    txt += to_string(txt.length());
    cout << "4. Дано рядок. Дописати в кінець рядка його довжину\t" << txt << endl;


    // 6. В заданому рядку вставити перед кожним символом «!» символ «,»
    txt = "!abcd!efghijklm!nopqr!stuv!wxyz";
    index = 0;
    while ((index = txt.find_first_of('!', index)) != string::npos) {
        index = txt.find_first_of('!', index);
        txt.insert(index, ",");
        index += 2;
    }        
    cout << "6. В заданому рядку вставити перед кожним символом «!» символ «,»\t" << txt << endl;

    
    // 7. Задані дві однакові за довжиною строки. Побудувати новий рядок, в якому на парних місцях розташовані елементи першого рядка, а на непарних - елементи другого рядка
    txt = "abcd";
    string txt1 = "1234";
    string txt2{};
    for (size_t i{ 0 }; i < txt.length(); i += 2) {
        txt2 += txt[i];
        txt2 += txt1[i + 1];
    }
    cout << "7. Задані дві однакові за довжиною строки. Побудувати новий рядок, в якому на парних місцях розташовані елементи першого рядка, а на непарних - елементи другого рядка\t" << txt2 << endl;
    //
    txt = "abcd";
    txt1 = "1234";
    for (size_t i{ 1 }; i < txt.length(); i += 2) txt.replace(i, 1, txt1.substr(i, 1));    
    cout << "7. Задані дві однакові за довжиною строки. Побудувати новий рядок, в якому на парних місцях розташовані елементи першого рядка, а на непарних - елементи другого рядка\t" << txt << endl;


    // 8. В заданому рядку замінити кожен пробіл двома пробілами
    txt = "aaaabcd efghijklm nopqr stuv wxyjz";
    index = 0;
    while ((index = txt.find_first_of(' ', index)) != string::npos) {
        index = txt.find_first_of(' ', index);
        txt.insert(index, " ");
        index += 2;
    }
    cout << "8. В заданому рядку замінити кожен пробіл двома пробілами\t" << txt << endl;


    // 15. В заданому рядку розташувати всі символи в порядку зростання їх кодів
    txt = "abcd efaghiscxjklfdfm nosdfpqr stfjukuuv wxloilyjz";
    for (size_t i{}; i < txt.length(); i++)
        for (size_t q{ i }; q < txt.length(); q++)
            if ((int)txt[i] > (int) txt[q])
                swap(txt[i], txt[q]);
    cout << "15. В заданому рядку розташувати всі символи в порядку зростання їх кодів\t'" << txt << '\'' << endl;

}