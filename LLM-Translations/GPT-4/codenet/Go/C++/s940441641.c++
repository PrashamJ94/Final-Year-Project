#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>

const int Inf = 1 << 60;

struct State {
    int cost, id;
    bool operator<(const State& o) const {
        return cost > o.cost;
    }
};

int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int& x, int& y, int& dir, int W) {
    x = id / 4 % W;
    y = id / 4 / W;
    dir = id % 4;
}

int main() {
    int H, W, K;
    std::cin >> H >> W >> K;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    std::swap(x1, y1);
    std::swap(x2, y2);

    std::vector<std::string> c(H);
    for (int y = 0; y < H; y++) {
        std::cin >> c[y];
    }

    std::vector<int> dx = {1, 0, -1, 0};
    std::vector<int> dy = {0, 1, 0, -1};

    std::vector<int> dist(W * H * 4, Inf);

    std::priority_queue<State> q;
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i, W)});
    }

    while (!q.empty()) {
        State now = q.top();
        q.pop();
        int x, y, dir;
        splatID(now.id, x, y, dir, W);
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[now.id] <= now.cost) {
            continue;
        }
        dist[now.id] = now.cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push({nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            q.push({nCost, nID});
        }
    }

    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < Inf) {
        std::cout << ans << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}

// 
