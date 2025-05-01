#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

// Arithmetic
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int ceil(int a, int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

// Main
const int MOD = int(1e+9) + 7;
const int INF = 1 << 60;

struct Mon {
    int x, h;
    bool operator<(const Mon &rhs) const {
        return x < rhs.x;
    }
};

struct Node {
    int x, h;
};

int main() {
    int N, D, A;
    cin >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }
    sort(M.begin(), M.end());
    queue<Node> q;
    int ans = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!q.empty() && q.front().x < m.x) {
            total -= q.front().h;
            q.pop();
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            int damage = count * A;
            q.push({m.x + 2 * D, damage});
            total += damage;
        }
    }

    cout << ans << endl;
    return 0;
}

// 
