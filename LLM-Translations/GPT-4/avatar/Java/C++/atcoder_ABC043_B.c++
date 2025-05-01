#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string s;
    std::cin >> s;
    std::stringstream d;
    for (char c : s) {
        switch (c) {
            case '0':
                d << "0";
                break;
            case '1':
                d << "1";
                break;
            case 'B':
                std::string current = d.str();
                if (!current.empty()) {
                    current.pop_back();
                    d.str("");
                    d << current;
                }
                break;
        }
    }
    std::cout << d.str() << std::endl;
    return 0;
}

// //End of Code.
