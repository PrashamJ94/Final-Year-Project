#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> C(10, std::vector<int>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cin >> C[i][j];
        }
    }

    std::vector<std::vector<int>> A(h, std::vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> dist(10, INF);
    dist[1] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < 10; ++v) {
            if (v == 1) continue;
            int alt = d + C[u][v];
            if (alt < dist[v]) {
                dist[v] = alt;
                pq.push({alt, v});
            }
        }
    }

    int s = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (A[i][j] == -1 || A[i][j] == 1) continue;
            s += dist[A[i][j]];
        }
    }

    std::cout << s << std::endl;

    return 0;
}
// 
