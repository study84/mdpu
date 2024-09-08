#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);

    //8. У заданому рядку розташувати у порядку все слова. Розділювачами слів вважаються прогалини

    string text{};
    //getline(cin, txt);
    text = "    Ackxcxi   Svcvcxui dskdasv xxiis idasi DOOS E";

    cout << "8. У заданому рядку розташувати у порядку все слова\n'" << text << '\'' << endl;

    string word;
    size_t start{}, stop{}, end_of_txt, count{};

    while ((start = text.find_first_not_of(":;., ", start)) != string::npos) {
        end_of_txt = text.find_first_of(":;., ", start);
        stop = end_of_txt != string::npos ? end_of_txt : text.length();
        word = text.substr(start, stop - start);
        count++;
        //cout << start << '-' << stop << '\t' << stop - start << "\t\'" << word << "\'\t" << endl;
        start = stop;
    }
    //cout << count << endl;


    string* words = new string[count];
    count = 0;
    start = 0;

    while ((start = text.find_first_not_of(":;., ", start)) != string::npos) {
        end_of_txt = text.find_first_of(":;., ", start);
        stop = end_of_txt != string::npos ? end_of_txt : text.length();
        words[count] = text.substr(start, stop - start);
        count++;
        //cout << *(words + count) << '\t' << text.substr(start, stop - start) << endl;
        start = stop;
    }

    for (size_t i{ 0 }; i < count + 1; i++)
        for (size_t ii{ i + 1 }; ii < count; ii++)
            if (words[i] > words[ii]) swap(words[i], words[ii]);

    cout << '\'';
    for (size_t i{}; i < count; i++) cout << words[i] << ' ';
    cout << '\'' << endl;

    delete[] words;

}