#include <stdio.h>

long long g1[8001], g2[8001], inverse[8001];
long long mod = 998244353;
long long K, N;

long long cmb(long long n, long long r, long long mod){
    if(r < 0 || r > n) return 0;
    r = (r < n-r ? r : n-r);

    return g1[n] * g2[r] % mod * g2[n-r] % mod;
}

void init(){
    g1[0] = 1;
    g1[1] = 1;
    g2[0] = 1;
    g2[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    for(long long i=2; i<=8001; i++){
        g1[i] = g1[i-1] * i % mod;
        inverse[i] = -inverse[mod % i] * (mod / i) % mod;
        g2[i] = g2[i-1] * inverse[i] % mod;
    }
}

long long kumiawase(long long p, long long q){
    return cmb(p + q - 1, q - 1, mod);
}

long long solve(long long n){
    long long ans = 0, kumi = (n - 1) / 2;
    for(long long p=0; p<=kumi; p++){
        if(p > N) break;
        ans += (1 << p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
        if(n % 2 == 0 && N - p - 1 >= 0)
            ans += (1 << p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
    }
    return ans;
}

int main(){
    scanf("%lld %lld", &K, &N);
    init();
    long long ans[2*K+1];
    for(long long i=2; i<=2*K; i++){
        if(i <= K + 1){
            ans[i] = solve(i) % mod;
            printf("%lld\n", ans[i]);
        } else printf("%lld\n", ans[2*K - i]);
    }
    return 0;
}
