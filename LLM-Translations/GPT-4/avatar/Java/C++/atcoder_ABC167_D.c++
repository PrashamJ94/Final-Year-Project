#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MOD = 1000000007;
const int MAX = INT32_MAX;
const long long LMAX = INT64_MAX;
int len = (int)1e6 + 1;

void doIt() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    set<int> used;
    vector<int> idx(N);
    vector<int> pos(N);
    int next = 0, cur = 0;
    while (used.find(next) == used.end()) {
        used.insert(next);
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long long a = (long long)cur - idx[next];
    long long b = (long long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    if (b > K) ans = (int)K;
    cout << pos[ans] + 1 << endl;
}

int main() {
    doIt();
    return 0;
}

// //End of Code
