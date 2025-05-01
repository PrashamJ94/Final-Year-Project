#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;

    std::cin >> N;
    std::cin >> S;

    int ans = 1;
    char tmp = S[0];
    for (char s : S) {
        if (s != tmp) {
            ans += 1;
            tmp = s;
        }
    }

    std::cout << ans << std::endl;

    return 0;
} // 
