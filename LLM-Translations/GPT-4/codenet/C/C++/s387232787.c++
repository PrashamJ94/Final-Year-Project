#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int c[26] = {0};
    string str;

    while(cin >> str) {
        for(char ch : str) {
            if(islower(ch)) {
                c[ch - 'a']++;
            } else if(isupper(ch)) {
                c[ch - 'A']++;
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        cout << static_cast<char>('a' + i) << " : " << c[i] << endl;
    }

    return 0;
}

// 
