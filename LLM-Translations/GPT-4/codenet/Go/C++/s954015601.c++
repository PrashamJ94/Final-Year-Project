#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int genid(int a, int b) {
    if (b < a) {
        swap(a, b);
    }
    return a * 100000 + b;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> ab(N - 1);
    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ab[i] = {a, b};
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    map<int, int> colors;
    deque<array<int, 3>> q;
    q.push_back({0, -1, -1});
    while (!q.empty()) {
        int currentNode = q.back()[0];
        int usedColor = q.back()[1];
        int parentNode = q.back()[2];
        q.pop_back();
        int color = 1;
        for (int childNode : edges[currentNode]) {
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            colors[genid(currentNode, childNode)] = color;
            q.push_back({childNode, color, currentNode});
            color++;
        }
    }

    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = edges[i].size();
        if (t > K) {
            K = t;
        }
    }
    cout << K << endl;

    for (int i = 0; i < N - 1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }

    return 0;
}
// 
