#include <iostream>
#include <vector>

std::vector<int> get_nums(int num, int t) {
    std::vector<int> result(num);
    for (int i = 0; i < num; ++i) {
        if (i < (t % num)) {
            result[i] = t / num + 1;
        } else {
            result[i] = t / num;
        }
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    std::cin >> n >> k >> l >> r >> sa >> sk;

    std::vector<int> ans1 = get_nums(k, sk);
    std::vector<int> ans2 = get_nums(n - k, sa - sk);
    ans1.insert(ans1.end(), ans2.begin(), ans2.end());

    for (int i : ans1) {
        std::cout << i << " ";
    }

    return 0;
} // End of Code.
