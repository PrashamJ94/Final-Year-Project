#include <iostream>
#include <string>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    if (S[K-1] == 'A') {
        S[K-1] = 'a';
    } else if (S[K-1] == 'B') {
        S[K-1] = 'b';
    } else {
        S[K-1] = 'c';
    }
    std::cout << S << std::endl;

    return 0;
}
// 
