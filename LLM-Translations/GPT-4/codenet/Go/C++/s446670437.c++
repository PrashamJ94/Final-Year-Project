#include <iostream>
#include <vector>
#include <string>

class Dice {
public:
    std::vector<int> Nums;

    void rotate(std::string direction, int times) {
        times %= 4;
        if (direction == "W") {
            for (int i = 0; i < times; i++) {
                std::swap(Nums[0], Nums[2]);
                std::swap(Nums[2], Nums[5]);
                std::swap(Nums[5], Nums[3]);
            }
        } else if (direction == "E") {
            for (int i = 0; i < times; i++) {
                std::swap(Nums[3], Nums[0]);
                std::swap(Nums[0], Nums[2]);
                std::swap(Nums[2], Nums[5]);
            }
        } else if (direction == "N") {
            for (int i = 0; i < times; i++) {
                std::swap(Nums[1], Nums[0]);
                std::swap(Nums[0], Nums[4]);
                std::swap(Nums[4], Nums[5]);
            }
        } else if (direction == "S") {
            for (int i = 0; i < times; i++) {
                std::swap(Nums[1], Nums[0]);
                std::swap(Nums[0], Nums[5]);
                std::swap(Nums[5], Nums[4]);
            }
        }
    }

    void roll(std::string direction, int times) {
        times %= 4;
        if (direction == "R") {
            for (int i = 0; i < times; i++) {
                std::swap(Nums[1], Nums[3]);
                std::swap(Nums[3], Nums[2]);
                std::swap(Nums[2], Nums[4]);
            }
        } else if (direction == "L") {
            for (int i = 0; i < times; i++) {
                std::swap(Nums[4], Nums[3]);
                std::swap(Nums[3], Nums[1]);
                std::swap(Nums[1], Nums[2]);
            }
        }
    }

    bool isEqual(const Dice& other) const {
        for (size_t i = 0; i < Nums.size(); i++) {
            if (Nums[i] != other.Nums[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Dice dice1, dice2;
    dice1.Nums.resize(6);
    dice2.Nums.resize(6);

    for (int i = 0; i < 6; i++) {
        std::cin >> dice1.Nums[i];
    }
    for (int i = 0; i < 6; i++) {
        std::cin >> dice2.Nums[i];
    }

    std::vector<std::string> directionOrder = {"N", "S", "W", "E"};
    std::vector<std::string> rollOrder = {"R", "L"};
    bool flag = false;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (const auto& direction : directionOrder) {
                for (const auto& roll : rollOrder) {
                    Dice tmp;
                    tmp.Nums = dice2.Nums;
                    tmp.rotate(direction, i);
                    tmp.roll(roll, j);
                    if (tmp.isEqual(dice1)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }

    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// 
