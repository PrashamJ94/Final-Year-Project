#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string str;
    while (std::cin >> str) {
        std::istringstream ss(str);
        std::string temp;
        std::vector<int> l(10);
        int d = 0;
        for (int i = 0; i < 10; i++) {
            std::getline(ss, temp, ',');
            l[i] = std::stoi(temp);
            d += l[i];
        }
        std::vector<int> v(2);
        for (int i = 0; i < 2; i++) {
            std::getline(ss, temp, ',');
            v[i] = std::stoi(temp);
        }
        double t = (double)d / (v[0] + v[1]);
        d = 0;
        for (int i = 0; i < 11; i++) {
            if (v[0] * t <= d) {
                std::cout << i << std::endl;
                break;
            } else {
                d += l[i];
            }
        }
    }
    return 0;
}
// 
