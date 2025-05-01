
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b) {
    tie(a, b) = make_tuple(max(a, b), min(a, b));
    while (a % b > 0) tie(a, b) = make_tuple(b, a % b);
    return b;
}

void solve() {
    string s;
    cin >> s;
    string t = "";
    int i = 0;
    while (i < s.size()) {
        if (s[i] == 'A') {
            t += 'A';
            i++;
        } else if (s[i] == 'B') {
            if (i < s.size() - 1) {
                if (s[i + 1] == 'C') {
                    t += 'D';
                    i += 2;
                } else {
                    t += 'X';
                    i++;
                }
            } else {
                t += 'X';
                i++;
            }
        } else {
            t += 'X';
            i++;
        }
    }
    int total = 0;
    int numA = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') numA++;
            else total += numA;
        }
    }
    cout << total << endl;
    const long long INF = 1LL << 60;
    const int mod = 1e9 + 7;
}

int main() {
    solve();
    return 0;
}

// End of Code.
