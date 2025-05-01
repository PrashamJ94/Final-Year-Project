#include <iostream>
#include <vector>
#include <regex>
#include <string>

int main() {
    int n, count;
    std::cin >> n;
    std::vector<int> num(n);
    
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    
    std::cin >> count;
    std::regex pt("(\\d+),(\\d+)");
    std::smatch matcher;
    std::vector<int> line(2);
    
    for (int i = 0; i < count; i++) {
        std::string next;
        std::cin >> next;
        std::regex_search(next, matcher, pt);
        
        for (int j = 0; j < line.size(); j++) {
            line[j] = std::stoi(matcher[j + 1]) - 1;
        }
        
        int change = num[line[0]];
        num[line[0]] = num[line[1]];
        num[line[1]] = change;
    }
    
    for (int i = 0; i < num.size(); i++) {
        std::cout << num[i] << std::endl;
    }
    
    return 0;
}
// 
