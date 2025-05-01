#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word;
    cin >> word;
    int uppercase = 0, lowercase = 0;
    for (int i = 0; i < word.length(); i++) {
        char ch = word[i];
        if (isupper(ch)) {
            uppercase++;
        } else {
            lowercase++;
        }
    }
    if (uppercase > lowercase) {
        for (auto &c : word) c = toupper(c);
        cout << word << endl;
    } else {
        for (auto &c : word) c = tolower(c);
        cout << word << endl;
    }
    return 0;
} // //End of Code
