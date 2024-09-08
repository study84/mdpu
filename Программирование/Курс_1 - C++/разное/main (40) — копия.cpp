const int size = 6;
char pattern[size + 1] = "dannie";
char pattern_symbols[size];
int pattern_offset[size + 1];

int offset{};
char symbol;
for (int p1{ size - 2 }, os{1}; p1 >= 0; p1--, os++) {

    symbol = pattern[p1];        
    offset = os;
    //cout << p1 << '\t' << symbol << '\t' << offset << endl;
    for (int i{ 0 }; i < size; i++)
        if (symbol == pattern_symbols[i]) {
            offset = pattern_offset[i];                
            break;
        }
    pattern_symbols[p1] = symbol;
    pattern_offset[p1] = offset;
}

symbol = pattern[size - 1];
offset = 6;
for (int i{ 0 }; i < size; i++)
    if (symbol == pattern_symbols[i]) {
        offset = pattern_offset[i];
        break;
    }
pattern_symbols[size - 1] = symbol;
pattern_offset[size - 1] = offset;



cout << endl;
for (int i{ 0 }; i < size; i++)
    cout << format("{}\t{}\t{}", i, pattern[i], pattern_offset[i]) << endl;
