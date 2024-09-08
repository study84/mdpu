// VECTOR

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    vector<int> myVector; // инициализация вектора
    //cout << myVector.size() << '\t' << myVector.capacity() << '\t' << endl;
    //cout << myVector[0] << endl;
    
    
    myVector.push_back(1); // добавить элемент к конец вектора
    myVector.push_back(22);
    myVector.push_back(333);
    myVector.push_back(4444);
    
    cout << myVector.size() << endl; // получить размер вектора
    cout << myVector[0] << endl; // вывести 0 элемент массива.
    cout << myVector[10] << endl; // вывести 10 элемент массива, который на данный момент не существует. может сгенерировать ошибку!
    //cout << myVector.at(10) << endl; // вывести 10й элемент массива, проверяет не выходт ли за границы вектора, сгенерирует ошибку, т.к. элемент за пределами размера вектора
    
    try {
        cout << myVector.at(10) << endl;
    }
    catch (const std::out_of_range& ex) {
        cout << ex.what() << endl;
    }
    
    //myVector.clear(); // очистка вектора
    
    cout << myVector.size() << endl;
    myVector.pop_back(); // удалить последний элемент
    cout << myVector.size() << endl;
    
    cout << myVector.capacity() << endl; // емкость вектора
    
    myVector.reserve(20); // изменение емкости вектора
    cout << myVector.capacity() << endl;
    
    vector<int> myVector2 = {0,1,2,3,4,5}; // инициализация вектора с присвоением значений
    cout << "myVector2.capacity " << myVector2.capacity() << endl;
    myVector2.reserve(4);
    cout << "myVector2.capacity -> myVector2.reserve(4) " << myVector2.capacity() << endl;
    
    myVector2.shrink_to_fit(); // отсекает не используемую честь вектора, урезая до size
    cout << myVector2.size() << '\t' << myVector2.capacity() << endl;
    
    vector<int> myVector3(20, 169); // инициалтзация вектора заданного размера с заданным значением
    cout << myVector3.size() << '\t' << myVector3.capacity() << '\t' << myVector3[0] << endl;
    cout << myVector3.empty() << endl; // является ли вектор пустым??? true - пустой, false - не пустой
    myVector3.resize(5, 144); // усечение вектора до указанного size, capacity останется прежним, default значения не поменяются на 144
    cout << myVector3.size() << '\t' << myVector3.capacity() << '\t' << myVector3[0] << endl;
    
    vector<int> myVector4;
    myVector4.resize(5, 144);
    cout << myVector4.size() << '\t' << myVector4.capacity() << '\t' << myVector4[0] << endl;
    
    //myVector2.reserve(4, 11);
    
    ////////////////////////////////////////////////////////////////////////////
    
    vector<int>myVector55 = {1,9,44,422,676,78};
    
    vector<int>::iterator it;
    it = myVector55.begin();
    cout << *it << '\t' << *(it + 1)<< endl;
    
    *it = 100;
    cout << *it << '\t' << *(it + 1)<< endl;
    
    it++;
    cout << *it << '\t' << *(it + 1)<< endl;
    
    it += 2;
    cout << *it << '\t' << *(it + 1)<< endl;
    
    
    for(vector<int>::iterator i = myVector55.begin(); i < myVector55.end(); i++) cout << *i << '\t';
    cout << endl;
    
    for(vector<int>::const_iterator i = myVector55.cbegin(); i < myVector55.cend(); i++) cout << *i << '\t';
    cout << endl;
    
    for(vector<int>::reverse_iterator i = myVector55.rbegin(); i < myVector55.rend(); i++) cout << *i << '\t';
    cout << endl;
    
    it = myVector55.begin();
    cout << *(it + 3) << endl;
    
    advance(it, 3); // Если итератор не поддерживает сдвиг вида "*(it + 3)", то используем эту функцию
    cout << *it << endl;
    
    //////////////////////////
    vector<int> myVector66 = {1,22,333,4444,55555,666666};
    
    cout << "myVector66: ";
    for(vector<int>::const_iterator mv = myVector66.cbegin(); mv < myVector66.cend(); mv++)
        cout << *mv << '\t';
    cout << endl;
    
    vector<int>::iterator mv66;
    mv66 = myVector66.begin();
    
    advance(mv66, 3);
    myVector66.insert(mv66, 101010);
    cout << "myVector66 insert: ";
    for(vector<int>::const_iterator mv = myVector66.cbegin(); mv < myVector66.cend(); mv++)
        cout << *mv << '\t';
    cout << endl;
    
    
    //mv66++;
    //myVector66.erase(mv66);
    vector<int>::iterator mv66_1 = myVector66.begin();
    advance(mv66_1, 4);
    myVector66.erase(mv66_1); // удалит указанный элемент
    //myVector66.erase(mv66_1, mv66_1 + 2); // удалить указанный диапазон
    
    cout << "myVector66 erase: ";
    for(vector<int>::const_iterator mv1 = myVector66.cbegin(); mv1 < myVector66.cend(); mv1++)
        cout << *mv1 << '\t';
    cout << endl;
    
    
    ////////
    
    vector<double> v1;
    for(auto i{0}; i < 10; i++) v1.push_back(2.5 * i);
    for(vector<double>::const_iterator d = v1.cbegin(); d < v1.cend(); d++) cout << *d << '\t';
    cout << endl;
    
    vector<double> v2;
    for(auto i{0}; i < 5; i++) v2.push_back(3.3 * i);
    for(vector<double>::const_iterator d = v2.cbegin(); d < v2.cend(); d++) cout << *d << '\t';
    cout << endl;
    
    v2.assign(v1.begin(), v1.end()); // заменить содержимое V2 срезом данных v1
    for(vector<double>::const_iterator d = v2.cbegin() + 1; d < v2.cend() - 1; d++) cout << *d << '\t';
    
    
    return 0;
}
