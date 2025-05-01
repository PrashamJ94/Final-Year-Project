
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int gcd(int a, int b) {
    return std::gcd(a, b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int lcm_list(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 1, lcm);
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        A[i] /= 2;
    }

    int count_div_2 = -1;
    for (int a : A) {
        int cnt = 0;
        while (a % 2 == 0) {
            a /= 2;
            cnt++;
        }
        if (count_div_2 == -1) {
            count_div_2 = cnt;
        } else if (cnt != count_div_2) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    int my_lcm = lcm_list(A);
    if (my_lcm > M) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int tmp = M / my_lcm;
    int ans = (tmp + 1) / 2;
    std::cout << ans << std::endl;

    return 0;
}


