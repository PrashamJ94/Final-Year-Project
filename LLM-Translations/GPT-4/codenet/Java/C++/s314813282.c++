#include <iostream>
#include <vector>
#include <algorithm>

int MaxInt(int x, std::vector<int> &a);
int MinInt(int y, std::vector<int> &b);
void CheckWar(int a, int b);

int main() {
    int m, n, x, y;
    std::cin >> m >> n >> x >> y;
    std::vector<int> a(m);
    for(int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    int x_max = MaxInt(x, a);
    int y_min = MinInt(y, b);
    CheckWar(x_max, y_min);
    return 0;
}

int MaxInt(int x, std::vector<int> &a) {
    int bignum = x;
    for(int i = 0; i < a.size(); i++) {
        bignum = std::max(bignum, a[i]);
    }
    return bignum;
}

int MinInt(int y, std::vector<int> &b) {
    int smallnum = y;
    for(int i = 0; i < b.size(); i++) {
        smallnum = std::min(smallnum, b[i]);
    }
    return smallnum;
}

void CheckWar(int a, int b) {
    if(a >= b) {
        std::cout << "War" << std::endl;
    } else {
        std::cout << "No War" << std::endl;
    }
}

// 
