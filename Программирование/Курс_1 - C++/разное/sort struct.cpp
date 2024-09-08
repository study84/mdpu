#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int age;
};

bool comparePersons(const Person& p1, const Person& p2) {
    // Сравниваем по возрасту, если возраст одинаковый, то по имени
    if (p1.age == p2.age) {
        return p1.name < p2.name;
    }
    return p1.age < p2.age;
}

int main() {
    std::vector<Person> people = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 20}};

    // Сортируем вектор people с использованием comparePersons
    std::sort(people.begin(), people.end(), comparePersons);

    // Выводим отсортированный список
    for (const auto& person : people) {
        std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
    }
	
	
	
	
	/////////////////////////
	
	list<string> names;
	list<string> sayings(20, "AAA");

	cout << names.size() << endl;
	cout << sayings.size() << endl;

	for (auto& s : sayings) s = "sdsdsdc";

	for (const auto& s : sayings) cout << s << endl;

    return 0;
}
