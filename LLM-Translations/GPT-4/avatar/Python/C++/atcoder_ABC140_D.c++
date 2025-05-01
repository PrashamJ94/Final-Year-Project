#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MOD int(1e9 + 7)

int main() {
    int N, K, seg_cnt = 0;
    cin >> N >> K;
    string S;
    cin >> S;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }
    int cur_happy = N - 1 - seg_cnt;
    int ans;
    if (2 * K >= seg_cnt) {
        ans = N - 1;
    } else {
        ans = cur_happy + 2 * K;
    }
    cout << ans;
    return 0;
}
//End of Code.
