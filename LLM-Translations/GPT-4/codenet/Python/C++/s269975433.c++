#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<tuple<int, int, int, int>> Q_groups(Q);
    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Q_groups[i] = make_tuple(a, b, c, d);
    }

    int max_score = 0;
    vector<int> p(N, 1);
    while (true) {
        int temp_score = 0;
        for (const auto& q : Q_groups) {
            if (p[get<1>(q) - 1] - p[get<0>(q) - 1] == get<2>(q)) {
                temp_score += get<3>(q);
            }
        }
        max_score = max(max_score, temp_score);

        bool done = false;
        for (int i = N - 1; i >= 0; --i) {
            if (p[i] < M) {
                ++p[i];
                fill(p.begin() + i + 1, p.end(), p[i]);
                done = true;
                break;
            }
        }

        if (!done) {
            break;
        }
    }

    cout << max_score << endl;

    return 0;
}
// 
