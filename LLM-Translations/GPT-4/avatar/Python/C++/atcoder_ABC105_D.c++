
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (long long i = 0; i < N; ++i){
        cin >> A[i];
    }
    vector<long long> cum_remainders(N+1, 0);
    for (long long i = 0; i < N; ++i){
        cum_remainders[i+1] = (cum_remainders[i] + A[i]) % M;
    }
    unordered_map<long long, long long> remainder_counts;
    for (long long i = 0; i <= N; ++i){
        remainder_counts[cum_remainders[i]]++;
    }
    long long combinations = 0;
    for (auto it = remainder_counts.begin(); it != remainder_counts.end(); ++it){
        long long count = it->second;
        combinations += count * (count - 1) / 2;
    }
    cout << combinations << endl;
    return 0;
}

// End of Code
