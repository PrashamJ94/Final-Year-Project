
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

const int mod = 1e9 + 7;

int max(int a, int b) {
    return a > b ? a : b;
}

std::map<int, int> primeFactorize(int n) {
    std::map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }
    if (n != 1) {
        res[n]++;
    }
    return res;
}

int pow(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k - 1) * n % mod;
    } else {
        int t = pow(n, k / 2);
        return t * t % mod;
    }
}

int add(int a, int b) {
    return (a + b) % mod;
}

int sub(int a, int b) {
    return (a + mod - b) % mod;
}

int mul(int a, int b) {
    return static_cast<long long>(a) % mod * b % mod % mod;
}

int div(int a, int b) {
    return mul(a, pow(b, mod - 2));
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    std::map<int, int> ps;
    for (int i = 0; i < n; i++) {
        std::cin >> as[i];

        std::map<int, int> ns = primeFactorize(as[i]);
        for (const auto& kv : ns) {
            ps[kv.first] = max(ps[kv.first], kv.second);
        }
    }

    int x = 1;
    for (const auto& kv : ps) {
        for (int i = 1; i <= kv.second; i++) {
            x = mul(x, kv.first);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, as[i]));
    }
    std::cout << ans << std::endl;

    return 0;
}


