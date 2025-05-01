#include <iostream>
#include <vector>
#include <algorithm>

int find(const std::vector<int>& li, int from, int target) {
    int low = from;
    int upp = li.size() - 1;
    int mid = (upp - low + 1) % 2 == 0 ? (low + upp) / 2 + 1 : (low + upp) / 2;

    if (upp - low < 0) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }

    while (upp - low > 1) {
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
        mid = (upp - low + 1) % 2 == 0 ? (low + upp) / 2 + 1 : (low + upp) / 2;
    }

    return low - from + 1;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> L(N);

    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    std::sort(L.begin(), L.end());

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i];
            int b = L[j];
            int res = find(L, j + 1, a + b);
            count += res;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

// //End of Code
