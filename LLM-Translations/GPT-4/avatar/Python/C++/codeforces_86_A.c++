#include<bits/stdc++.h>
using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;
    long long curr = r;
    long long s = 0;
    while (curr) {
        s += 1;
        curr /= 10;
    }
    long long first = pow(10, s);
    long long second = first / 2;
    long long ans = -1;
    for (long long i : {l, r, first, second}) {
        if (i >= l && i <= r) {
            curr = i;
            string rev = "";
            for (char k : to_string(curr)) {
                rev += to_string(9 - (k - '0'));
            }
            ans = max(ans, stoll(rev) * curr);
        }
    }
    cout << ans << endl;
    return 0;
} //End of Code.
