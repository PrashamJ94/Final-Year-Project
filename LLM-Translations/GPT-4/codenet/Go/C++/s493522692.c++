
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int maxInt(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int minInt(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int N, M;
    cin >> N >> M;

    int tmp = minInt(N, M / 2);
    int ans = 0;
    ans += tmp;
    N -= tmp;
    M -= tmp * 2;

    cout << ans + M / 4 << endl;

    return 0;
}

// 
