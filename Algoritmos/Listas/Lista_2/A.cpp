#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string beiju_text(string input_string) {
    vector<char> begin, end;
    bool home = false;

    for (char& c : input_string) { // substitua "char" por "c" ou outro nome de variável
        if (c == '[') {
            home = true;
            reverse(begin.begin(), begin.end());
        } else if (c == ']') {
            home = false;
            reverse(begin.begin(), begin.end());
        } else {
            if (home) {
                begin.push_back(c);
            } else {
                end.push_back(c);
            }
        }
    }

    reverse(begin.begin(), begin.end());
    begin.insert(begin.end(), end.begin(), end.end());

    return string(begin.begin(), begin.end());
}

int main() {
    string input_string;
    while (getline(cin, input_string)) {
        cout << beiju_text(input_string) << endl;
    }

    return 0;
}