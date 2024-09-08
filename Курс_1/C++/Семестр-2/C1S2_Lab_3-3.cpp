#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    string txt{}, word1, word2;
    //getline(cin, txt);
    size_t index{};
    
    
    // 1. У заданому рядку поміняти місцями перше та останнє слово рядка. Розділювачами слів вважаються прогалини
    txt = "asd fghjk zxc";
    word1 = txt.substr(0, txt.find_first_of(' '));
    word2 = txt.substr(txt.find_last_of(' ') + 1);
    txt.erase(0, txt.find_first_of(' '));
    txt.erase(txt.find_last_of(' ') + 1);
    txt += word1;
    word2 += txt;
    cout << "1. У заданому рядку поміняти місцями перше та останнє слово рядка. Розділювачами слів вважаються прогалини\t" << word2 << endl;

    
    // 2. Задано два рядки. Побудувати новий рядок, що складається з символів, які входять як до одного, так і до іншого рядка.
    word1 = "xbuweyruwxyfuvv";
    word2 = "etorriunc guic";
    txt = "";
    for (size_t i{}; i < word1.length(); i++)
        if ((txt.find(word1[i]) == string::npos) and (word2.find(word1[i]) != string::npos))
            txt += word1.substr(i, 1);
    cout << "2. Задано два рядки. Побудувати новий рядок, що складається з символів, які входять як до одного, так і до іншого рядка\t" << txt << endl;
    

    // 3. Задано два рядки. Побудувати новий рядок, що складається з символів, які входять до першого рядка, але не входять до другого
    word1 = "xbuweyruwxyfuvv";
    word2 = "etorriunc guic";
    txt = "";
    for (size_t i{}; i < word1.length(); i++)
        if ((txt.find(word1[i]) == string::npos) and (word2.find(word1[i]) == string::npos))
            txt += word1.substr(i, 1);
    cout << "3. Задано два рядки. Побудувати новий рядок, що складається з символів, які входять до першого рядка, але не входять до другого\t" << txt << endl;


    // 4. У заданому рядку замінити кожен символ "*" числом, що відповідає номеру за порядком входження цього символу в рядок.
    txt = "niu*xef*8dsv*8x8*dg*fk";
    index = 1;
    while (txt.find_first_of('*') != string::npos) {
        txt.replace(txt.find_first_of('*'), 1, to_string(index));
        index++;
    }        
    cout << "4. У заданому рядку замінити кожен символ * числом, що відповідає номеру за порядком входження цього символу в рядок\t" << txt << endl;


    // 5. У заданому рядку замінити кожен символ "!" числом, рівним індекс цього символу в рядку
    txt = "niu!xef!8dsv!8x8!dg!fk";
    index = 0;
    while ((index = txt.find_first_of('!')) != string::npos) txt.replace(index, 1, to_string(index));
    cout << "5. У заданому рядку замінити кожен символ ! числом, рівним індекс цього символу в рядку\t" << txt << endl;


    // 7. У заданому рядку порахувати кількість різних символів, що входять до цього рядка
    txt = "niu!xef!8dsv!8x8!dg!fk";
    word1 = "";
    for (size_t i{}; i < txt.length(); i++)
        if (word1.find(txt[i]) == string::npos) word1 += txt[i];
    cout << "7. У заданому рядку порахувати кількість різних символів, що входять до цього рядка\t" << word1.length() << endl;


    //8. У заданому рядку розташувати у порядку все слова. Розділювачами слів вважаються прогалини


    // 9. У заданому рядку порахувати кількість слів, що містять лише малі літери. Розділювачами слів вважаються прогалини    
    txt = "    Ackxcxi   Svcvcxui dskdasv xxiis idasi DOOS E"; // "", " ", "asasasas"    
    string t, alf{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    size_t start{}, stop{}, end_of_txt, count{}, test{};

    while ((start = txt.find_first_not_of(":;., ", start)) != string::npos) {
        end_of_txt = txt.find_first_of(":;., ", start);
        stop = end_of_txt != string::npos ? end_of_txt : txt.length();
        t = txt.substr(start, stop - start);
        test = 0;
        for (char letter : t) test += (alf.find_first_of(letter) != string::npos ? 0 : 1);
        //cout << start << '-' << stop << '\t' << stop - start << "\t\'" << t << "\'\t" << test << '\t' << ((stop - start) == test) << endl;
        count += ((stop - start) == test) ? 1 : 0;
        start = stop;
    }
    cout << "9. У заданому рядку порахувати кількість слів, що містять лише малі літери\t" << count << endl;

}