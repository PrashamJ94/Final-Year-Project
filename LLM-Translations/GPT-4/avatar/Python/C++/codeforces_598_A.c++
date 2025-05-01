#include<iostream>
using namespace std;

long long solve (long long n) {
    long long s = (1 + n) * n / 2;
    long long t = 1;
    while (t <= n) {
        s -= 2 * t;
        t *= 2;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

//End of Code
