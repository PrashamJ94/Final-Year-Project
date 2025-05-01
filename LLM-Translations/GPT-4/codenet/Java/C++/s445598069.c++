#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);

    std::vector<int> s(100010, 0);

    int num;
    while (iss >> num) {
        s[num]++;
    }

    int dec = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 0) {
            if (s[i] % 2 == 0) {
                s[i] = 2;
            } else {
                s[i] = 1;
            }
        }
    }

    int one = 0;
    int two = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 2) {
            two++;
        } else if (s[i] == 1) {
            one++;
        }
    }

    if (two % 2 != 0) {
        one--;
    }

    std::cout << two + one << std::endl;

    return 0;
}
// 
