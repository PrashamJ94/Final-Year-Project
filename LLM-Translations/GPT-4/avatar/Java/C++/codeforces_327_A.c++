#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int checKNo(const std::vector<int>& brr) {
    int val = 0;
    for (int i : brr) {
        if (i == 1) {
            ++val;
        }
    }
    return val;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x = 0;
            std::vector<int> brr(n);

            for (int k : arr) {
                brr[x++] = k;
            }

            for (int k = i; k <= j; k++) {
                if (brr[k] == 0) {
                    brr[k] = 1;
                } else {
                    brr[k] = 0;
                }
            }

            int count = checKNo(brr);
            if (count > max) {
                max = count;
            }
        }
    }

    if (n == 1) {
        if (arr[0] == 1) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    } else {
        std::cout << max << std::endl;
    }

    return 0;
}

// //End of Code.
