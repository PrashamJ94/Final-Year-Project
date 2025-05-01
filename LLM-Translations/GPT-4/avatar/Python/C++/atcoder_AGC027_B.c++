#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];

    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin());

    int ans = INT_MAX;
    for(int k=0; k<N; k++) {
        int E = k * X;
        for(int j=N-2*k-2; j>=0; j-=k)
            E += 2 * S[j];
        ans = min(ans, E);
    }

    cout << ans + N * X + 5 * S[N-1] << endl;

    return 0;
}
// End of Code

Please note that this is a direct translation of the Python code you've provided to C++. In C++, we use the `partial_sum` function from the `numeric` library to achieve what `accumulate` does in Python. Also, in C++ we use `INT_MAX` for representing infinity. This code assumes that the input is well-formed and doesn't perform any error checking.
