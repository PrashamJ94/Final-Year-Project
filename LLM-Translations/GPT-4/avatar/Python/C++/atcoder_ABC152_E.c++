#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while(y>0){
        if(y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i=0; i<N; i++)
        cin >> A[i];
    ll _lcm = 1;
    ll sum = 0;
    for(ll a : A){
        _lcm = (_lcm * a) / gcd(_lcm, a);
        sum += power(a, MOD-2, MOD);
        sum %= MOD;
    }
    ll ans = (_lcm * sum) % MOD;
    cout << ans << endl;
    return 0;
}

//End of Code
