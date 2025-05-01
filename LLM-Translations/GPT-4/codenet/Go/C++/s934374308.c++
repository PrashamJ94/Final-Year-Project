#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    int N, K, R, S, P;
    std::string T;
    std::cin >> N >> K >> R >> S >> P;
    std::cin >> T;

    std::map<std::string, int> dict = {{"r", 0}, {"s", 0}, {"p", 0}};
    std::string char_;
    std::vector<bool> s(N, true);
    std::vector<bool> r(N, true);
    std::vector<bool> p(N, true);
    for (int i = 0; i < N; i++) {
        s[i] = true;
    }
    for (int i = 0; i < N; i++) {
        char_ = T.substr(i, 1);
        if (i >= K) {
            if (char_ == T.substr(i - K, 1)) {
                if (char_ == "s") {
                    if (s[i % K]) {
                        s[i % K] = false;
                        continue;
                    } else {
                        s[i % K] = true;
                    }
                } else if (char_ == "r") {
                    if (r[i % K]) {
                        r[i % K] = false;
                        continue;
                    } else {
                        r[i % K] = true;
                    }
                } else if (char_ == "p") {
                    if (p[i % K]) {
                        p[i % K] = false;
                        continue;
                    } else {
                        p[i % K] = true;
                    }
                }
            } else {
                if (char_ == "s") {
                    s[i % K] = true;
                } else if (char_ == "r") {
                    r[i % K] = true;
                } else if (char_ == "p") {
                    p[i % K] = true;
                }
            }
        }
        if (char_ == "s") {
            dict["s"] = dict["s"] + 1;
        } else if (char_ == "r") {
            dict["r"] = dict["r"] + 1;
        } else if (char_ == "p") {
            dict["p"] = dict["p"] + 1;
        }
    }

    int res = P * dict["r"] + S * dict["p"] + R * dict["s"];
    std::cout << res << std::endl;

    return 0;
}

// 
