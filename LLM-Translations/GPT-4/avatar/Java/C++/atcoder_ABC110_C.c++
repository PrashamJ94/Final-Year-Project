#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    std::vector<char> A = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    bool res = true;

    for (char s : A) {
        int sIdx = S.find(s);
        if (sIdx == std::string::npos) continue;
        char t = T[sIdx];
        int idx = 0;

        while (idx < S.length()) {
            int sPos = S.find(s, idx);
            int tPos = T.find(t, idx);

            if (sPos != std::string::npos) {
                if (sPos != tPos) {
                    res = false;
                    break;
                } else {
                    idx = sPos + 1;
                }
            } else if (tPos != std::string::npos) {
                res = false;
                break;
            } else {
                break;
            }
        }

        if (!res) break;
    }

    if (res) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
// //End of Code
