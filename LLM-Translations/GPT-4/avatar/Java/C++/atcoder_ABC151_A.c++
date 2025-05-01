cpp
#include <iostream>
#include <string>
using namespace std;

class RemRing {
    long long module;
public:
    RemRing(long long module) {
        this->module = module;
    }
    long long sum(long long a, long long b) {
        return (a + b + module) % module;
    }
    long long sub(long long a, long long b) {
        return (a - b + module) % module;
    }
    long long prod(long long a, long long b) {
        return (a * b) % module;
    }
    long long div(long long a, long long b) {
        return (a * inv(b)) % module;
    }
    long long inv(long long a) {
        long long b = this->module;
        long long u = 1;
        long long v = 0;
        while (b > 0) {
            long long t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        u %= this->module;
        if (u < 0) u += this->module;
        return u;
    }
};

int main() {
    string s;
    cin >> s;
    printf("%c", s[0] + 1);
    return 0;
}

// //End of Code
