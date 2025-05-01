
#include <iostream>
#include <vector>

int main() {
    int info[4][3][10] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                info[i][j][k] = 0;
            }
        }
    }

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int built, floor, room, num;
        std::cin >> built >> floor >> room >> num;
        info[built - 1][floor - 1][room - 1] += num;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                std::cout << " " << info[i][j][k];
            }
            std::cout << "\n";
        }
        if (i != 4 - 1) {
            std::cout << "####################\n";
        }
    }

    return 0;
}

// 
