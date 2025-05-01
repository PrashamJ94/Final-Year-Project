#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Arithmetic
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int ma = max(A, B, C);
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    cout << (ma + rest) << endl;

    return 0;
}

// 
