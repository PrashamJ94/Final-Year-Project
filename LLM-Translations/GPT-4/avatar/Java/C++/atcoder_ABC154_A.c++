#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::vector<std::string> str;
    int a, b;
    std::string u;

    // Read first line
    getline(std::cin, line);
    std::istringstream iss(line);
    for (std::string s; iss >> s;)
        str.push_back(s);

    // Read second line
    std::cin >> a >> b;

    // Read third line
    std::cin >> u;

    // Print result
    std::cout << (u == str[0] ? (a - 1) : a) << " " << (u == str[0] ? b : (b - 1)) << std::endl;

    return 0;
}

// //End of Code.
