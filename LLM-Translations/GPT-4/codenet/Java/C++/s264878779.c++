#include <iostream>
#include <string>
#include <vector>
#include <bitset>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    long long ans = 0;
    for(int mask = 0; mask < 1<<(n - 1); mask++) {
        long long sum = 0;
        std::string x = "" + s.at(0);
        for(int i = 0; i < n - 1; i++) {
            if((mask & (1<<i)) >= 1) {
                x += "+" + s.at(i + 1);
            } else {
                x += s.at(i + 1);
            }
        }
        std::vector<std::string> split;
        size_t pos = 0;
        std::string token;
        while ((pos = x.find('+')) != std::string::npos) {
            token = x.substr(0, pos);
            split.push_back(token);
            x.erase(0, pos + 1);
        }
        split.push_back(x);

        for(int i = 0; i < split.size(); i++) {
            sum += std::stoll(split[i]);
        }
        ans += sum;
    }
    std::cout << ans << std::endl;
    return 0;
}

// 
