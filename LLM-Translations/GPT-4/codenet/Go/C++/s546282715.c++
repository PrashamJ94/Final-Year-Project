#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

int getNextInt(std::istream &is) {
    int i;
    is >> i;
    return i;
}

int main(int argc, char *argv[]) {
    std::istream *fp = &std::cin;
    std::ifstream ifs;
    if(argc > 1) {
        ifs.open(argv[1]);
        fp = &ifs;
    }

    int n = getNextInt(*fp);
    int m = getNextInt(*fp);
    std::unordered_map<int, int> aa;
    for(int i = 0; i < m; i++) {
        aa[getNextInt(*fp)] = 1;
    }

    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if(aa.find(i + ii) != aa.end()) {
                continue;
            }
            dp[i + ii] += dp[i];
            dp[i + ii] %= 1000000007;
        }
    }
    std::cout << dp[n] << std::endl;

    return 0;
}

// 
