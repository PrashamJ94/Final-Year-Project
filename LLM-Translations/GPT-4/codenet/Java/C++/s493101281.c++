#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

class Pair {
public:
    int key;
    int value;
    Pair(int k, int v) : key(k), value(v) {}
    int getKey() { return key; }
    int getValue() { return value; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> l(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    cout << l[n / 2] - l[n / 2 - 1] << endl;

    return 0;
}
// 
