#include <iostream>
#include <vector>
#include <string>

void solve(int H, int W, int A, int B) {
    std::vector<std::vector<char>> answer(H, std::vector<char>(W, '0'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {
                if (j < A)
                    answer[i][j] = '0';
                else
                    answer[i][j] = '1';
            } else {
                if (j < A)
                    answer[i][j] = '1';
                else
                    answer[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << answer[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int H, W, A, B;
    std::cin >> H >> W >> A >> B;
    solve(H, W, A, B);
    return 0;
}

// End of Code
