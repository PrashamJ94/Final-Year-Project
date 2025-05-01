#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    long i = 357;
    int c = 0;

    while (i <= N) {
        string s = to_string(i);
        if (s.find('3') != string::npos && s.find('5') != string::npos && s.find('7') != string::npos)
            c++;

        string sb;
        bool f = false;

        for (int j = 0; j < s.length(); j++) {
            char a = s[s.length() - 1 - j];

            if (f) {
                sb.push_back(a);
            } else {
                if (a == '3') {
                    sb.push_back('5');
                    f = true;
                } else if (a == '5') {
                    sb.push_back('7');
                    f = true;
                } else {
                    sb.push_back('3');
                }
            }
        }

        if (!f)
            sb.push_back('3');

        reverse(sb.begin(), sb.end());
        i = stol(sb);
    }

    cout << c << endl;

    return 0;
}

// //End of Code
