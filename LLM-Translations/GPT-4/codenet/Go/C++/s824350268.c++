#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const int mod = 1e9 + 7;

int getInt() {
    int i;
    cin >> i;
    return i;
}

string getString() {
    string s;
    cin >> s;
    return s;
}

int abs(int a) {
    return abs(a);
}

int pow(int p, int q) {
    return pow(p, q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % mod;
    } else {
        return (n * powMod(n, p - 1)) % mod;
    }
}

int min(int a, int b) {
    return min(a, b);
}

int max(int a, int b) {
    return max(a, b);
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int N = getInt();
    int sqrtN = (int)sqrt(N);

    int minNum = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < minNum) {
            minNum = num;
        }
    }

    cout << minNum << endl;

    return 0;
}

// 
