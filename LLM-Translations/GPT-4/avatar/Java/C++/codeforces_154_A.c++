#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int N = input.length();
    set<string> set;
    int K;
    cin >> K;
    int res = 0;
    for (int k = 0; k < K; k++) {
        string s;
        cin >> s;
        int a = 0;
        int b = 0;
        for (int i = 0; i < N; i++) {
            if (input[i] == s[0]) {
                a++;
            } else if (input[i] == s[1]) {
                b++;
            } else {
                res += min(a, b);
                a = b = 0;
            }
        }
        res += min(a, b);
    }
    cout << res << endl;
    return 0;
} // //End of Code
