#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];

    int result = 0;
    for(int b = 0; b < 60; b++) {
        int bs = 0;
        for(int i = 0; i < N; i++)
            if(A[i] & (1LL << b))
                bs++;

        result = (result + bs * (N - bs) * (1LL << b)) % MOD;
    }

    cout << result << "\n";

    return 0;
}
// End of Code


