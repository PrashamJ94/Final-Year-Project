#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 999999999999999999999999
#define MOD 1000000007

ll n;
vector<ll> factorize(ll n){
    vector<ll> a;
    while(n%2==0){
        a.push_back(2);
        n/=2;
    }
    ll f=3;
    while(f*f<=n){
        if(n%f==0){
            a.push_back(f);
            n/=f;
        }
        else{
            f+=2;
        }
    }
    if(n!=1){
        a.push_back(n);
    }
    return a;
}

int main(){
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        exit(0);
    }
    vector<ll> fac_=factorize(n);
    unordered_map<ll,ll> fac;
    for(ll i:fac_){
        fac[i]++;
    }
    ll ans=0;
    for(auto& it:fac){
        ll x=it.second;
        for(ll i=1;i<99999999;++i){
            if(x>=i){
                x-=i;
                ans++;
            }
            else{
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
} // End of Code.
