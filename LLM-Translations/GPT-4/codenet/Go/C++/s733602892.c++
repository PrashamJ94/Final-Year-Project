#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include <iterator>

int readInt() {
    int v;
    std::cin >> v;
    return v;
}

std::vector<int> readInts(int n) {
    std::vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        ret[i] = readInt();
    }
    return ret;
}

int main() {
    int N = readInt();
    int K = readInt();
    std::vector<int> As = readInts(N);
    std::vector<int> Fs = readInts(N);

    std::sort(As.begin(), As.end());
    std::sort(Fs.rbegin(), Fs.rend());
    std::vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        scores[i] = As[i] * Fs[i];
    }
    std::sort(scores.rbegin(), scores.rend());

    int ok = scores[0];
    int ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; ++i) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    std::cout << ok << std::endl;

    return 0;
}

// 
