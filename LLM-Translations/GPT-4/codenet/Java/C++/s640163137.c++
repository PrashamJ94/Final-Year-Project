#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<int> a(n);
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    for (int i = 0; i < n; i++) {
        iss >> a[i];
    }

    int swapCount = 0;

    for (int i = 0; i < a.size(); i++) {
        int mini = i;

        for (int j = i; j < a.size(); j++) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }

        if (mini != i) {
            std::swap(a[mini], a[i]);
            swapCount++;
        }
    }

    std::string ans = std::to_string(a[0]);
    for (int i = 1; i < a.size(); i++) {
        ans += " " + std::to_string(a[i]);
    }

    std::cout << ans << std::endl;
    std::cout << swapCount << std::endl;
    
    return 0;
}
// 
