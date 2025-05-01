#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <fstream>

int main(int argc, char* argv[]) {
    std::ifstream input;
    std::ofstream output;
    std::istream* in = &std::cin;
    std::ostream* out = &std::cout;

    if (argc > 1) {
        input.open(argv[1]);
        in = &input;
        if (argc > 2) {
            output.open(argv[2]);
            out = &output;
        }
    }

    int n;
    *in >> n;
    std::vector<int> ll(n);

    for (int i = 0; i < n; i++) {
        *in >> ll[i];
    }

    std::sort(ll.begin(), ll.end());

    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i + 1; j < n-1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            ans += l - (j + 1);
        }
    }
    *out << ans << std::endl;

    return 0;
}
// 
