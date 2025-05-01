#include<bits/stdc++.h>
using namespace std;
int par[200005], sz[200005], h[200005];
long long ans;
priority_queue<pair<int,int> > pq;

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x,int y){
    if((x=find(x))!=(y=find(y))){
        if(sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y];
        par[y] = x;
    }
}

int main(){
    int n, a, b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        pq.push({a,i});
        par[i] = i;
        sz[i] = 1;
    }
    while(!pq.empty()){
        a = pq.top().first;
        b = pq.top().second;
        pq.pop();
        ans += 1LL * a * sz[find(b)];
        if(h[b-1] < a) unite(b, b-1);
        if(h[b+1] < a) unite(b, b+1);
        h[b] = a;
    }
    printf("%lld\n",ans);
    return 0;
}

// End of Code.
