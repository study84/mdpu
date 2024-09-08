#include <iostream>
#include <string>
//#include <format>


using namespace std;

int main()
{
    
    string txt;
    txt = "txt";
    
    string txt1{"txt1"};
    
    txt.length(); // Длинна строки, не включает символ конца стороки
    
    string txt2{txt2};
    
    string txt3{"txt333", 4}; // Создаст строку длинной 4 
    
    cout << txt3 << endl;
    
    string txt4{'T'};
    cout << txt4 << endl;
    
    string txt5{'T', 'X'};
    cout << txt5 << '\t' << txt5[0] << endl;
    
    string txt6(6, 'x'); // Количество повторений, символ
    //string txt7(7, "*"); // Количество повторений, символ
    cout << txt6 << '\t' << txt6[0] << endl;
    
    string txt7{"abcdef", 3, 3}; // Срез строки: строка, индекс начала, длинна
    cout << txt7 << endl;
    
    string txt8{"abcdef", 3}; // Срез строки: строка, показать первых Х символов
    cout << txt8 << endl;
    
    
    string txt9{"txt9"};
    string txt10{"txt10"};
    string txt11{txt9 + " " + txt10 + " txt11" }; // Конкатенация
    //
    cout << txt11 << endl;
    
    
    for (size_t i{}; i < txt11.length(); i++) txt11[i] = static_cast<char>(toupper(txt11[i]));
    cout << txt11 << endl;
    
    
    short l{0};
    string text{"You’ve seen how you can use an array... string"};
    //getline(cin, text);
    for (size_t i{}; i < text.length(); i++) {
        if (isalpha(text[i])) {
            switch (tolower(text[i])) {
                case 'a': case 'e': case 'i': case 'o': case 'u': 
                cout << text[i] << '\t';
                l++; break;
            }
        }
    }
    cout << l << endl;
    
    
    string txt12 {"The higher the fewer"}; 
    string txt13{txt12.substr(4,6)}; // Срез подстроки по позициям (стар, число символов)
    string txt14{txt12.substr(4)}; // Срез подстроки по позициям (старт и до конца)
    cout << txt13 << '\t' << txt14 << endl;
    
    // Порівняння рядків > >= < <= == != <=>
    // string arr1[]{"A"};
    // string arr2[]{"a"};
    // const short t{8};
    // string test[t];
    // for (size_t l{}; l < arr1.length(); l++){
    //     test[0] = arr1[l] + ' ' + arr2[l] + '\t';
    //     test[1] = "(1>2)=" + (arr1[l] > arr2[l]) + ' ';
    //     test[2] = "(1>=2)=" + (arr1[l] >= arr2[l]) + ' ';
    //     test[3] = "(1<2)=" + (arr1[l] < arr2[l]) + ' ';
    //     test[4] = "(1<=2)=" + (arr1[l] <= arr2[l]) + ' ';
    //     test[5] = "(1==2)=" + (arr1[l] == arr2[l]) + ' ';
    //     test[6] = "(1!=2)=" + (arr1[l] != arr2[l]) + ' ';
    //     //test[7] = "1<=>2:" + (arr1[l] <=> arr2[l]) + ' ';
    //     test[7] = "1<=>2:";
    //     for (auto i{0}; i < t; i++) cout << test[i];
    //     cout << endl;
    // }
    
    //<=> 
    #include <compare>
    int a = 5;
    int b = 10;
    std::weak_ordering result = a <=> b;
    if (result < 0) cout << "a меньше b" << std::endl;
    else if (result == 0) cout << "a равно b" << std::endl;
    else cout << "a больше b" << std::endl;
    
    
    // "compare" = "<=>"
    string word1{"A jackhammer"}, word2{"jack"};
    cout << word1 << '\t' << word2 << '\t' << word1.compare(2, word2.length(), word2) << endl;
    
    //Пошук рядків
    string sentence {"Manners maketh man"}, word {"man"};
    cout << sentence.find(word) << endl; // поиск подстроки по умолчанию начиная с символа 0
    cout << sentence.find("Ma") << endl; // поиск подстроки по умолчанию начиная с символа 0
    cout << sentence.find('k') << endl; // поиск подстроки по умолчанию начиная с символа 0
    cout << sentence.find('n', 4) << endl; // поиск подстроки по умолчанию начиная с указанного номера символа символа
    cout << (sentence.find('q') == string::npos) << endl; // если смивол не найден, вернет тип данных "npos" при проверке bool это true
    
    // string text; // The string to be searched
    // string word; // Substring to be found
    // cout << "Enter the string to be searched and press Enter:\n"; // Smith, where Jones had had "had had", had had "had". "Had had" had had the examiners' approval.
    // getline(std::cin, text);
    // cout << "Enter the string to be found and press Enter:\n"; //had
    // getline(std::cin, word);
    // size_t count{}; // Count of substring occurrences
    // size_t index{}; // String index
    // while ((index = text.find(word, index)) != string::npos)
    //     {
    //     ++count;
    //     index += word.length(); // Advance by full word (discards overlapping occurrences)
    //     }
    // cout << "Your text contained " << count << " occurrences of \""  << word << "\"." << endl;
    
    // string text {"Smith, where Jones had had \"had had\", had had \"had\"." " \"Had had\" had had the examiners' approval."};
    // string separators {" ,.\""};
    // std::cout << text.find_first_of(separators) << std::endl; //Пошук будь-якого з набору символів
    
    // Пошук у рядку назад
    // std::string sentence {"Manners maketh man"};
    // std::string word {"an"};
    // std::cout << sentence.rfind(word) << std::endl;

    string phrase {"1234567"};
    string words {"*"};
    
    phrase.insert(0, words); // номер позиции, подстрока, которую нужно вставить
    cout << phrase << endl;
    
    
    insert(size_t pos, const std::string& str, size_t subpos, size_t sublen);
    pos - это позиция, на которую нужно вставить символы или подстроку в строку.
    str - подстрока, которую нужно вставить.
    subpos - начальная позиция вставки подстроки str.
    sublen - количество символов из подстроки str, которые нужно вставить.
    
    phrase = "1234567890";
    phrase.insert(1, "abcdef", 1, 3); 
    cout << phrase << endl;
    
    
    std::string text {"Smith, where Jones had had \"had had\", had had \"had\"."};
    text.replace(13, 5, "Gruntfuttock"); // Старт подстроки, длинна подстроки, заменить "на"
    
    const std::string separators {" ,;:.\"!'\n"}; // Розділювачі слів
    size_t start {text.find("Jones")}; // Знайдіть підрядок
    size_t end {text.find_first_of(separators, start + 1)}; // Знайди кінець
    text.replace(start, end - start, "Gruntfuttock");
    
    
    string text {"Smith, where Jones had had \"had had\", had had \"had\"."};
    const string separators {" ,;:.\"!'\n"}; // Розділювачі слів
    size_t start {text.find("Jones")}; // Знайдіть підрядок 13
    size_t end {text.find_first_of(separators, start + 1)}; // Знайди кінець 18
    text.replace(start, end - start, "Gruntfuttock"); //13, 5, Gruntfuttock
    cout << text;
    
    
    // Видалення символів із рядка
    
    phrase.erase(0, 3);
    cout << '>' << phrase << endl;
    
    phrase.erase(phrase.length() / 2);
    cout << '>' << phrase << endl;
    
    phrase.replace(1, 1, ""); // удаляем* 1 символ
    cout << '>' << phrase << endl;
    
    phrase.erase();
    cout << '>' << phrase << endl;
    
    
    Перетворення рядків у числа
    std::string s{ "123" };
    int i{ std::stoi(s) }; // i == 123
    double d{ stod(s) };
    d+=0.1;
    cout<<d;

    return 0;
}