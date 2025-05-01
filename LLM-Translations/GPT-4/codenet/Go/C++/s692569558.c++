#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string ds;
    std::getline(std::cin, ds);

    std::istringstream iss(ds);
    std::vector<int> dn;
    int temp;
    while (iss >> temp) {
        dn.push_back(temp);
    }

    int sum = 0;
    for (int i = 0; i < dn.size(); i++) {
        for (int j = i + 1; j < dn.size(); j++) {
            sum += dn[i] * dn[j];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
// 
