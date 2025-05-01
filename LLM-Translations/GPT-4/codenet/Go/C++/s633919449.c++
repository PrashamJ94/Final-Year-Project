#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_set>
#include <stack>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <list>
#include <tuple>
#include <numeric>
#include <functional>
#include <cassert>
#include <climits>
#include <stdexcept>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    switch (N % 10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
        cout << "hon" << endl;
        break;
    case 0:
    case 1:
    case 6:
    case 8:
        cout << "pon" << endl;
        break;
    case 3:
        cout << "bon" << endl;
        break;
    }

    return 0;
}

class Graph {
public:
    int n;
    vector<vector<int>> edges;

    Graph(int n) {
        this->n = n;
        edges = vector<vector<int>>(n);
    }

    void AddEdge(int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
};

void dfs(int c, vector<vector<int>>& edges, unordered_set<int>& visited) {
    visited.insert(c);

    for (int v : edges[c]) {
        if (visited.count(v)) {
            continue;
        }
        dfs(v, edges, visited);
    }
}

void bfs(int c, Graph& graph) {
    queue<int> next;
    next.push(c);
    unordered_set<int> visited;

    while (!next.empty()) {
        int u = next.front();
        next.pop();
        visited.insert(u);

        for (int v : graph.edges[u]) {
            if (visited.count(v)) {
                continue;
            }

            // Do some processing

            next.push(v);
        }
    }
}

int pow_mod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = pow_mod(n, p / 2);
        return (1LL * t * t) % mod;
    } else {
        return (1LL * n * pow_mod(n, p - 1)) % mod;
    }
}

bool is_prime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> get_divisor(int n) {
    unordered_set<int> divisor;
    divisor.insert(1);
    if (n != 1) {
        divisor.insert(n);
    }

    int sqrt = sqrt(n);
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }

    vector<int> divisorArray(divisor.begin(), divisor.end());
    return divisorArray;
}

// 
