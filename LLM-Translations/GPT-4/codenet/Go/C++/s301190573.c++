#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

const int size = 1000000;
std::vector<int> par, rank;

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void initialize(int n) {
    par.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int root(int i) {
    if (par[i] == i) { return i; }
    par[i] = root(par[i]);
    return par[i];
}

bool same(int i, int j) {
    return root(i) == root(j);
}

void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) { return; }
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        if (rank[i] == rank[j]) { rank[i]++; }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }
    initialize(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        unite(x - 1, y - 1);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) { s++; }
    }
    std::cout << s << std::endl;
    return 0;
}
// 
