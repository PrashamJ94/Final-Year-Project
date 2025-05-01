#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, std::string> map;
    int n;
    std::cin >> n;
    std::string str;
    std::getline(std::cin, str);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, str);
        map[str] = "";
    }

    std::cout << map.size() << std::endl;

    return 0;
}

// 
