
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2e31;
const int MAX_SIZE = 1010;

int H, W, si, sj, ti, tj;
int S[MAX_SIZE][MAX_SIZE], D[MAX_SIZE][MAX_SIZE];

void grid_dijkstra() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            D[i][j] = -1;
        }
    }
    deque<tuple<int, int, int>> que;
    que.push_front(make_tuple(0, si, sj));
    while(!que.empty()) {
        int c, i, j;
        tie(c, i, j) = que.front();
        que.pop_front();
        if (D[i][j] != -1) continue;
        D[i][j] = c;
        for(int di = -2; di <= 2; di++) {
            for(int dj = -2; dj <= 2; dj++) {
                int ni = i + di, nj = j + dj;
                if (!(0 <= ni && ni < H && 0 <= nj && nj < W) || D[ni][nj] != -1 || ni == nj == 0 || S[ni][nj] == 1) continue;
                if ((di == 0 && abs(dj) == 1) || (dj == 0 && abs(di) == 1)) {
                    que.push_front(make_tuple(c, ni, nj));
                } else {
                    que.push_back(make_tuple(c + 1, ni, nj));
                }
            }
        }
    }
}

int main() {
    cin >> H >> W;
    cin >> si >> sj;
    cin >> ti >> tj;
    si--; sj--; ti--; tj--;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            char ch;
            cin >> ch;
            S[i][j] = (ch == '#' ? 1 : 0);
        }
    }

    grid_dijkstra();
    cout << D[ti][tj] << endl;

    return 0;
}


