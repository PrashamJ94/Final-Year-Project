#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N , M;
    cin >> N >> M;

    vector<pair<int, int>> balls(N, make_pair(1, 0));
    balls[0] = make_pair(0, 1);

    for (int i = 0; i < M; i++) {
        int x , y;
        cin >> x >> y;
        x--; y--;

        int w_x = balls[x].first;
        int r_x = balls[x].second;
        int w_y = balls[y].first;
        int r_y = balls[y].second;

        if (w_x >= 1 && r_x >= 1){
            balls[x].first -= 1;
            balls[y].second += 1;
        }
        else if (w_x == 0){
           balls[x].second -= 1;
           balls[y].second += 1;
        }
        else {
            balls[x].first -= 1;
            balls[y].first += 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        if (balls[i].second){
            ans += 1;
        }
    }

    cout << ans << "\n";

    return 0;
}

// End of Code.
