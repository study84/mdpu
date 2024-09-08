// Лекція 3. Прийняття рішень
// https://dfn.mdpu.org.ua/pluginfile.php/36265/mod_resource/content/1/c%2B%2BПрийняття%20рішень%20лек3.pdf

#include <windows.h>
#include <iostream>
#include <compare> // Required when using operator <=> (even for fundamental types)

using namespace std;

/*
Глобальні змінні
Змінні, які оголошені поза всіма блоками і класами (про класи йдеться пізніше), називаються глобальними, вони мають глобальну область
видимості (яка також називається областю видимості глобального простору імен або областю видимості файлу ).
Глобальні змінні також за умовчанням мають статичну тривалість зберігання
*/
long count1{ 999L };



int main() {
	SetConsoleOutputCP(1251);
		
	/*
	Існують три тривалості зберігання змінних :
		• автоматична;
		• статична;
		• динамічна
	*/

	cout << "count1 (значення на глобальному рівні) = " << count1 << endl;

	{
		cout << "{" << endl;
		int count1{ 10 };
		cout << "\tcount1 (значення в поточному блоці) = " << count1 << endl;

		cout << "\tcount1 (значення на глобальному рівні) = " << ::count1 << endl;

		count1 += ::count1;
		cout << "\tcount1 + ::count1 (значення в поточному блоці) = " << count1 << endl;

		++::count1;
		cout << "\t++count1 (значення на глобальному рівні) = " << ::count1 << endl;

		cout << "}" << endl;
		
	}

	/*
	Статичні змінні
	Необхідно мати можливість оголосити змінну , що має область видимості в межах блоку, але забезпечити статичний період зберігання. Специфікатор static забезпечує таку можливість.
	static int count;
	*/

	/*char letter{ 0 };
	cin >> letter;
	if ((letter >= ' А') && (letter <= 'Z')) cout << " Це велика буква.";*/
	
	
	int a{10}, b{5};
	cout << "Тернарний IF" << (a > b ? "+" : 0) << endl;

	//std::strong_ordering ordering{ 10 <=> 0 }; ???????????????????????????????????????????????

	char letter{};
	std::cout << "Введіть літеру: ";
	std::cin >> letter;
	if (std::isalpha(letter))
	{
		switch (std::tolower(letter))
		{
		case 'a': case 'e': case 'i': case 'o': case 'u':
			cout << "Ви ввели голосну букву." << endl; break;
		default: cout << "Ви ввели приголосну." << endl; break;
		}
	}
	else cout << "Ви не ввели букву." << endl;

	return 0;
}