#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> G(H + 2);
    G[0] = G[H + 1] = string(W + 2, '#');
    for (int i = 1; i <= H; ++i) {
        cin >> G[i];
        G[i] = "#" + G[i] + "#";
    }

    int ans = 0;
    for (int sx = 0; sx < W + 2; ++sx) {
        for (int sy = 0; sy < H + 2; ++sy) {
            if (G[sy][sx] == '.') {
                vector<vector<int>> dist(H + 2, vector<int>(W + 2, numeric_limits<int>::min()));
                vector<vector<int>> visited(H + 2, vector<int>(W + 2, -1));
                queue<pair<int, int>> q;
                q.push({sx, sy});
                dist[sy][sx] = 0;
                visited[sy][sx] = 1;
                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();

                    if (G[y][x + 1] == '.' && visited[y][x + 1] == -1) {
                        q.push({x + 1, y});
                        dist[y][x + 1] = dist[y][x] + 1;
                        visited[y][x + 1] = 1;
                    }

                    if (G[y][x - 1] == '.' && visited[y][x - 1] == -1) {
                        q.push({x - 1, y});
                        dist[y][x - 1] = dist[y][x] + 1;
                        visited[y][x - 1] = 1;
                    }

                    if (G[y + 1][x] == '.' && visited[y + 1][x] == -1) {
                        q.push({x, y + 1});
                        dist[y + 1][x] = dist[y][x] + 1;
                        visited[y + 1][x] = 1;
                    }

                    if (G[y - 1][x] == '.' && visited[y - 1][x] == -1) {
                        q.push({x, y - 1});
                        dist[y - 1][x] = dist[y][x] + 1;
                        visited[y - 1][x] = 1;
                    }
                }
                for (int i = 0; i < W + 2; ++i) {
                    for (int j = 0; j < H + 2; ++j) {
                        ans = max(ans, dist[j][i]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// 
