#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    long long number;
    cin >> number;

    long long ans = -1, value = 0;
    int mask = 2;

    while (value < number) {
        string s = bitset<64>(mask++).to_string().substr(1);

        int zeros = 0;
        for (char c : s) {
            if (c == '0') {
                zeros++;
            }
        }

        if (zeros != s.length() - zeros) {
            continue;
        }

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                s[i] = '4';
            } else if (s[i] == '1') {
                s[i] = '7';
            }
        }

        value = stoll(s);
    }

    cout << value << endl;

    return 0;
}

// //End of Code
