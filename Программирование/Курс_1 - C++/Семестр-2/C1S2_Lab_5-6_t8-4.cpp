#include <windows.h>
#include <iostream>
#include <format>
#include <string>

using namespace std;

string maximum_reverse_substring_search(string txt);

int main()
{
    SetConsoleOutputCP(1251);

    cout << "8 (Дуже складно) Напишіть функцію мовою C++, яка отримує в якості аргументів символьний масив та його розмір і повертає новий масив, що містить довжину найдовшого спільного підрядка вихідного масиву та його зворотний розмір." << endl;
        
    string text{ "the red racecar speeds quickly on the racetrack" };

    //cout << "введіть речення ";
    //cin >> text;    

    cout << text << endl;

    cout << maximum_reverse_substring_search(text);

    return 0;
}


string maximum_reverse_substring_search(string txt) {    
    string txt_reverse{}, substr_temp{}, substr{};
    for (char t : txt) txt_reverse.insert(0, 1, t);

    cout << format("{}\t'{}'\t{}", txt, txt_reverse, txt_reverse.length()) << endl;

    short max{ 0 }, first{ 0 }, len{ 0 }, index{0};
    
    
    auto skip = [](char c) {
        string symbols = ":;., ";
        return symbols.find(c) == string::npos;
        };

    
    for (short f{ 0 }; f < txt_reverse.length(); f++) {
        //if (skip(txt_reverse[f])) continue;       
        
        for (short l{ 1 }; l < txt_reverse.length() + 1 - f; l++) {
            substr_temp = txt_reverse.substr(f, l);
            //cout << format("{} - {}\t'{}'", f, l, substr_temp);
            if (txt.find(substr_temp) != string::npos) {
                //index = 0;
                //while ((index = word.find_first_of(":;., ", index)) != string::npos) word.erase(index, 1);
                //cout << format("\t> '{}'", word);
                if (substr_temp.length() > max) {
                    max = substr_temp.length();
                    substr = substr_temp;
                }
                    
            }
            else break;
            //cout << endl;
        }    
    }
    
    return format("'{}'", substr);
}