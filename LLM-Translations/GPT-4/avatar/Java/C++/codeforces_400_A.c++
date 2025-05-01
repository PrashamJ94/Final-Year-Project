#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isSolution(int columnsCount, const std::string& x) {
    std::vector<bool> allXs(columnsCount, true);
    for (int i = 0; i < 12; ++i) {
        if (x[i] != 'X') allXs[i % columnsCount] = false;
    }
    for (int i = 0; i < columnsCount; ++i) {
        if (allXs[i]) return true;
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int possibleSolutions = 0;
        std::string solutions;
        std::string s;
        std::cin >> s;
        if (isSolution(12, s)) {
            solutions.append(" 1x12");
            possibleSolutions++;
        }
        if (isSolution(6, s)) {
            solutions.append(" 2x6");
            possibleSolutions++;
        }
        if (isSolution(4, s)) {
            solutions.append(" 3x4");
            possibleSolutions++;
        }
        if (isSolution(3, s)) {
            solutions.append(" 4x3");
            possibleSolutions++;
        }
        if (isSolution(2, s)) {
            solutions.append(" 6x2");
            possibleSolutions++;
        }
        if (isSolution(1, s)) {
            solutions.append(" 12x1");
            possibleSolutions++;
        }
        std::cout << possibleSolutions << solutions << std::endl;
    }
    return 0;
}
// //End of Code.
