#include <iostream>
#include <vector>
#include <string>

class Data {
public:
    int n, m;
    std::vector<std::string> nImg, mImg;

    Data(int n, int m, std::vector<std::string>& nImg, std::vector<std::string>& mImg)
        : n(n), m(m), nImg(nImg), mImg(mImg) {}

    bool exist() {
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (match(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool match(int x, int y) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (nImg[x + i][y + j] != mImg[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> nImg(n), mImg(m);
    for (int i = 0; i < n; i++) {
        std::cin >> nImg[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> mImg[i];
    }

    Data d(n, m, nImg, mImg);
    if (d.exist()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
// 
