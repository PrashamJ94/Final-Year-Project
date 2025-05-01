#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> shop;

bool compare(const shop &a, const shop &b) {
    return a.first < b.first;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<shop> s(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        s[i] = make_pair(a, b);
    }
    sort(s.begin(), s.end(), compare);

    int total = 0;
    for (const auto &e : s) {
        int n = min(e.second, M);
        total += n * e.first;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    cout << total << endl;

    return 0;
}
// 
