#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    int m, s, f;
    std::cin >> m >> s >> f;
    int maxT = -1;
    std::map<int, std::vector<int>> map;

    while (m > 0) {
        int k, a, b;
        std::cin >> k >> a >> b;
        map[k] = std::vector<int>{a, b};
        maxT = std::max(maxT, k);
        m--;
    }

    std::string actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1;
    int b = -1;

    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) {
            a = map[t][0];
            b = map[t][1];
        }

        if (map.find(t) != map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions += 'X';
        } else {
            actions += M;
            cur += d;
        }

        if (cur == f) break;
    }

    while (cur != f) {
        actions += M;
        cur += d;
    }

    std::cout << actions << std::endl;

    return 0;
} // //End of Code
