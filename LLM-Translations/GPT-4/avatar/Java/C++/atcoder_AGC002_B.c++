#include <iostream>
#include <vector>

class Box {
public:
    int num;
    bool red;

    Box(int n, bool r) : num(n), red(r) {}

    void moveTo(Box &other) {
        if (num == 0) {
            return;
        } else if (num == 1) {
            num = 0;
            other.num++;
            if (red) {
                other.red = true;
            }
            red = false;
        } else {
            num--;
            other.num++;
            if (red) {
                other.red = true;
            }
        }
    }
};

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<Box> B;
    B.push_back(Box(1, true));
    for (int i = 1; i < N; i++) {
        B.push_back(Box(1, false));
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
        B[x].moveTo(B[y]);
    }
    int counter = 0;
    for (Box &b : B) {
        if (b.red) {
            counter++;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}

// //End of Code.
