#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int gcd_val = gcd(n, m);
    long long lcm_val = (long long)n * m / gcd_val;

    vector<int> positions(gcd_val);
    for (int k = 0; k < gcd_val; k++) {
        if (s[k * n / gcd_val] != t[k * m / gcd_val]) {
            positions.push_back(-1);
        }
    }

    if (find(positions.begin(), positions.end(), -1) != positions.end()) {
        cout << "-1" << endl;
    } else {
        cout << lcm_val << endl;
    }

    return 0;
}
// //End of Code
