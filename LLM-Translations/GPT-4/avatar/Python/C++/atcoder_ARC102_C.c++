#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int MAX = 8000;
long long g1[MAX+1], g2[MAX+1], inverse[MAX+1];

long long cmb(int n, int r){
    if(r < 0 || r > n) return 0;
    r = min(r, n - r);
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}

long long kumiawase(int p, int q){
    return cmb(p + q - 1, q - 1);
}

long long solve(int n, int K, int N){
    assert(n <= K + 1);
    long long ans = 0;
    int kumi = (n - 1) / 2;
    for(int p = 0; p <= kumi; ++p){
        if(p > N) break;
        ans += pow(2, p) * cmb(kumi, p) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
        if(n % 2 == 0 && N - p - 1 >= 0){
            ans += pow(2, p) * cmb(kumi, p) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
    }
    return ans % mod;
}

int main(){
    int K, N;
    cin >> K >> N;
    g1[0] = g1[1] = g2[0] = g2[1] = 1;
    inverse[0] = inverse[1] = 1;
    for(int i = 2; i <= MAX; ++i){
        g1[i] = g1[i - 1] * i % mod;
        inverse[i] = mod - inverse[mod%i] * (mod / i) % mod;
        g2[i] = g2[i - 1] * inverse[i] % mod;
    }
    vector<long long> ans;
    for(int i = 2; i <= 2*K; ++i){
        if(i <= K + 1){
            long long tmp = solve(i, K, N);
            ans.push_back(tmp);
            cout << tmp << "\n";
        }else{
            cout << ans[2*K - i] << "\n";
        }
    }
    return 0;
}

// End of Code.
