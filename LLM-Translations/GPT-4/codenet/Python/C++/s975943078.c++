#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] = (A[i] % K) - 1;
    }
    vector<int> sum_A(N + 1, 0);

    int count = 0;
    map<int, vector<int>> modK;
    modK[0] = {0};
    for (int i = 0; i < N; i++) {
        sum_A[i + 1] = (sum_A[i] + A[i]) % K;
        if (modK.find(sum_A[i + 1]) == modK.end()) modK[sum_A[i + 1]] = {i + 1};
        else modK[sum_A[i + 1]].push_back(i + 1);
    }

    for (const auto &key_val : modK) {
        int lenK = key_val.second.size();
        for (int i = 0; i < lenK; i++) {
            int a = key_val.second[i];
            count += lower_bound(modK[key_val.first].begin() + i + 1,
                                 modK[key_val.first].end(), a + K) -
                     (modK[key_val.first].begin() + i + 1);
        }
    }

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}
// 
