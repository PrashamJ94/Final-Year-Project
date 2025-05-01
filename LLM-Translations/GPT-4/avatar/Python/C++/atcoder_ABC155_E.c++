#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

bool isTest = false;

void pa(ll v) {
    if (isTest) {
        cout << v << endl;
    }
}

ll main_b(string s) {
    ll pp = 0;
    ll na = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        ll cc = na + (s[i] - '0');
        na = 0;
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if (i == 0) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }
    return pp;
}

ll main_a(string s) {
    ll pmin = 1000;
    ll mmin = 0;
    s = '0' + s;
    for (int i = s.length() - 1; i >= 0; i--) {
        ll v = s[i] - '0';
        ll npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        ll nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    return min(pmin, mmin);
}

int main() {
    string s;
    cin >> s;
    ll ret = main_a(s);
    if (ret != -1) {
        cout << ret << endl;
    }
    return 0;
}

// End of Code
