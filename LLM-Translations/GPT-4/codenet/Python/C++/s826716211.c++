#include <iostream>
#include <string>
#include <algorithm>

void solve() {
    std::string S_d;
    std::cin >> S_d;
    std::string T;
    std::cin >> T;

    int end = S_d.length() - 1;
    int first = end - T.length() + 1;

    while (first >= 0) {
        int t_i = 0;
        for (int s_i = first; s_i <= end; ++s_i) {
            if (T[t_i] != S_d[s_i] && S_d[s_i] != '?') {
                break;
            }
            t_i++;
        }
        if (t_i == T.length()) {
            break;
        }
        first--;
        end--;
    }

    if (first < 0) {
        std::cout << "UNRESTORABLE" << std::endl;
        return;
    }

    std::string ans = S_d;
    int t_i = 0;
    for (int i = first; i <= end; ++i) {
        ans[i] = T[t_i];
        t_i++;
    }

    std::replace(ans.begin(), ans.end(), '?', 'a');
    std::cout << ans << std::endl;
}

int main() {
    solve();
    return 0;
}
// 
