
#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    if (N == 0) {
        return 0;
    }

    if (N < 4) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') {
            nr++;
        }

        if (c == 'B') {
            nb++;
        }

        if (c == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i += 1;
            j += 1;
            k += 1;
        }
    }

    int tot = nr * nb * ng;
    std::cout << tot - same << std::endl;

    return 0;
}


