#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int twos_in_factorial(int n) {
    return n - bitset<32>(n).count();
}

bool parity_of_nCr(int n, int i) {
    int f = twos_in_factorial;
    return f(n) - f(n - i) - f(i) > 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i]--;
    }
    bool no_one = true;
    for (int num : nums) {
        if (num == 1) {
            no_one = false;
            break;
        }
    }
    if (no_one) {
        for (int& num : nums) {
            num /= 2;
        }
    }
    bool is_odd = false;
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd = !is_odd;
        }
    }
    if (!is_odd) {
        cout << 0 << endl;
    } else {
        cout << (1 << no_one) << endl;
    }
    return 0;
} // End of Code

Please note the differences in handling of bitwise operations and bit counting between Python and C++. Also, lambda functions and list comprehensions in Python don't have direct analogs in C++, so loops are used instead.
