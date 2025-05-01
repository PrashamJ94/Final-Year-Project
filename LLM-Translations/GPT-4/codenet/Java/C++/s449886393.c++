#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> youbi = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    std::string s;
    std::cin >> s;
    int ans = 0;
    for(int i = 0; i < youbi.size(); i++) {
        if (youbi[i] == s) {
            ans = 7 - i;
        }
    }
    std::cout << ans << std::endl;
    
    return 0;
}
// 
