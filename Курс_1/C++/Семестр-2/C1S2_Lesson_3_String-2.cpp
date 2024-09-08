// Количество вхождений подстроки
#include <iostream>
#include <string>

using namespace std;

int countSubstringOccurrences(const string& str, const string& substr) {
    int count = 0;
    size_t pos = 0;

    while ((pos = str.find(substr, pos)) != string::npos) {
        count++;
        pos += substr.length();
    }

    return count;
}

int main() {
    
    cout << "Number of occurrences: " << countSubstringOccurrences("abababababab", "aba") << endl;
    cout << "Number of occurrences: " << countSubstringOccurrences("ds7d    sd sd  sds   asd   8xzc ", "  ") << endl;

    return 0;
}
