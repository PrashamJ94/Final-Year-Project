
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> train(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        train[l - 1][r - 1] += 1;
    }

    vector<vector<int>> accum(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
        int v = 0;
        for (int j = 0; j < N; ++j) {
            v += train[i][j];
            accum[i + 1][j + 1] = accum[i][j + 1] + v;
        }
    }

    for (int i = 0; i < Q; ++i) {
        int p, q;
        cin >> p >> q;
        int v = accum[q][q] - accum[p - 1][q] - accum[q][p - 1] + accum[p - 1][p - 1];
        cout << v << endl;
    }

    return 0;
}

// 
