#include <iostream>

int main() {
    int R, G, B, N;
    std::cin >> R >> G >> B >> N;

    int score = 0;
    for (int i = 0; i <= N / R; ++i) {
        for (int j = 0; j <= (N - i * R) / G; ++j) {
            if (N - i * R - j * G >= 0 && (N - i * R - j * G) % B == 0) {
                score += 1;
            }
        }
    }

    std::cout << score << std::endl;

    return 0;
}
// 
