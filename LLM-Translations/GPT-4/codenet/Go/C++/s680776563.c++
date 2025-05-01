
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdio>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (B - A == C - B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

// Max, Min
int IntMax(int a, int b) {
    return (a < b) ? b : a;
}

int64_t Int64Max(int64_t a, int64_t b) {
    return (a < b) ? b : a;
}

double Float64Max(double a, double b) {
    return (a < b) ? b : a;
}

int IntMin(int a, int b) {
    return (a > b) ? b : a;
}

int64_t Int64Min(int64_t a, int64_t b) {
    return (a > b) ? b : a;
}

double Float64Min(double a, double b) {
    return (a > b) ? b : a;
}

// Gcd
int IntGcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    return (b == 0) ? a : IntGcd(b, a % b);
}

int64_t Int64Gcd(int64_t a, int64_t b) {
    if (a < b) {
        swap(a, b);
    }
    return (b == 0) ? a : Int64Gcd(b, a % b);
}

// Abs
int IntAbs(int a) {
    return (a < 0) ? -a : a;
}

int64_t Int64Abs(int64_t a) {
    return (a < 0) ? -a : a;
}

// 
