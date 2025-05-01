#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <bitset>
#include <cmath>

class FastScanner {
public:
    std::string next() {
        if (!st.hasMoreElements()) {
            std::string line;
            std::getline(std::cin, line);
            st = std::istringstream(line);
        }
        std::string token;
        st >> token;
        return token;
    }

    int nextInt() {
        return std::stoi(next());
    }

private:
    std::istringstream st;
};

class Main {
public:
    void solve() {
        FastScanner fs;

        h = fs.nextInt();
        w = fs.nextInt();
        k = fs.nextInt();

        colorMtr.resize(h);
        for (int i = 0; i < h; i++) {
            std::string line;
            std::getline(std::cin, line);
            colorMtr[i] = line;
        }

        int hPattern = std::pow(2, h);
        int wPattern = std::pow(2, w);

        int ans = 0;

        for (int i = 0; i < hPattern; i++) {
            for (int j = 0; j < wPattern; j++) {
                if (judge(i, j)) {
                    ans++;
                }
            }
        }

        std::cout << ans << std::endl;
    }

private:
    std::vector<std::string> colorMtr;
    int h;
    int w;
    int k;

    bool judge(int hPattern, int wPattern) {
        std::bitset<32> hBitArr(hPattern);
        std::bitset<32> wBitArr(wPattern);

        int black = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (hBitArr[i] || wBitArr[j]) {
                    continue;
                }

                if (colorMtr[i][j] == '#') {
                    black++;
                }
            }
        }

        return black == k;
    }
};

int main() {
    Main mainObj;
    mainObj.solve();
    return 0;
}

// 
