#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    
    string txt{"abcdef123"};
    //getline(cin, txt);

    const size_t len = txt.length();
    string c1{}, c2{};
    
    // 1. В заданому рядку підрахувати кількість літер «А».
    size_t task1{};
    for (size_t i{}; i < len; i++) if (toupper(txt[i]) == 'A') task1 += 1;
    cout << "1. В заданому рядку підрахувати кількість літер «А»\t" << task1 << endl;

    
    // 2. В заданому рядку обміняти місцями перший та останній символ.
    //swap(phrase[0], phrase[len - 1]);
    c1 = txt[0];
    c2 = txt[len - 1];
    txt.replace(len - 1, 1, c1);
    txt.replace(0, 1, c2);
    cout << "2. В заданому рядку обміняти місцями перший та останній символ\t'" << txt << '\'' << endl;


    // 3. В заданому рядку замість першого символу вставити пробіл, а замість останнього - крапку
    txt.replace(0, 1, " ");
    txt.replace(len - 1, 1, ".");
    cout << "3. В заданому рядку замість першого символу вставити пробіл, а замість останнього - крапку\t'" << txt << '\'' << endl;


    // 4. В заданому рядку видалити перший символ
    txt.erase(0, 1);
    cout << "4. В заданому рядку видалити перший символ\t'" << txt << '\'' << endl;


    // 5. В заданому рядку додати в кінець рядка символ «@»
    txt += "@";
    cout << "5. В заданому рядку додати в кінець рядка символ «@»\t'" << txt << '\'' << endl;


    // 6. В заданому рядку підрахувати кількість символів цифр (від «0» до «9»)
    size_t cout_num{ 0 };
    for (size_t i{}; i < len; i++) if (isdigit(txt[i])) cout_num++;
    cout << "6. В заданому рядку підрахувати кількість символів цифр (від «0» до «9»)\t" << cout_num << endl;


    // 7. Визначити, чи є в заданому рядку символ цифри
    cout << "7. Визначити, чи є в заданому рядку символ цифри\t" << (txt.find_first_of("0123456789") ? "True":"False") << endl;


    // 8. В заданому рядку замість кожного пробілу вставити символ «»
    // 9. В заданому рядку видалити останній символ.
    // 10. В заданому рядку видалити всі пробіли


    // 11. В заданому рядку видалити другий і четвертий символи за рахунком
    txt.erase(1, 1);
    txt.erase(3, 1);
    cout << "11. В заданому рядку видалити другий і четвертий символи за рахунком\t'" << txt << '\'' << endl;


    // 12. Знайти суму кодів всіх символів заданого рядка
    short symbol_code{ 0 };
    for (size_t i{}; i < len - 1; i++) symbol_code += (int)txt[i];
    cout << "12. Знайти суму кодів всіх символів заданого рядка\t" << symbol_code << endl;


    // 13. Видалити перше слово заданого рядка. Роздільником слів вважається пробіл
    //txt.erase(0, txt.find_first_of(" ") == string::npos ? 0 : txt.find_first_of(" ") + 1);
    txt = txt.substr(txt.find_first_of(" ") == string::npos ? 0 : txt.find_first_of(" ") + 1);
    cout << "13. Видалити перше слово заданого рядка. Роздільником слів вважається пробіл\t'" << txt << '\'' << endl;

    
    // 14. В заданому рядку підрахувати кількість крапок і ком
    // 15. В заданому рядку підрахувати кількість круглих і квадратних дужок
    // 16. Помістити заданий рядок у лапки вигляду «»
    
    
    // 17. На кінець заданого рядка додати символи «_», досягаючи довжини рядка 25
    string s(25 - txt.length(), '_');
    txt += s;
    cout << "17. На кінець заданого рядка додати символи «_», досягаючи довжини рядка 25\t'" << txt << '\'' << endl;


    // 18. Для заданого рядка визначити, чи містить він принаймні одну українську літеру
    // 19. Для заданого рядка визначити, чи містить він принаймні одну латинську літеру
    // 20. В заданому рядку знайти місцезнаходження першого символу «*»

    
    // 21. Видалити в заданому рядку все, крім першого і останнього символів
    txt.erase(1, txt.length() - 2);
    cout << "21. Видалити в заданому рядку все, крім першого і останнього символів\t'" << txt << '\'' << endl;


    // 22. Для заданого рядка визначити, які символи частіше зустрічаються, «!» чи « ? »
    // 23. В заданому рядку визначити, чи співпадає кількість круглих дужок, які відкривають і круглих дужок, які закривають

}