
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N+2), diff(N);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int ans = abs(A[N+1]);
    A[0] = 0;
    A[N+1] = 0;
    for(int i = 1; i <= N; i++) {
        int dif = abs(A[i] - A[i-1]) + abs(A[i] - A[i+1]) - abs(A[i-1] - A[i+1]);
        ans += abs(A[i] - A[i-1]);
        diff[i-1] = dif;
    }

    for(int i = 0; i < N; i++) {
        cout << ans - diff[i] << endl;
    }

    return 0;
}


