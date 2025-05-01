#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <unistd.h>

using namespace std;

int32_t nextint(){
    char c=getchar_unlocked(); 
    while(c!='-'&&(c<'0'||'9'<c)) c=getchar_unlocked(); 
    bool s=false; 
    if(c=='-'){s=true;c=getchar_unlocked();}
    uint32_t x=0; 
    while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } 
    return s?-x:x; 
}

int n;

int p(int a, int b){
    if(a<b){
        return a+b*n;
    }else{
        return b+a*n;
    }
}

vector<vector<int>> a(1000, vector<int>(999));

vector<int> e1(1000000);
vector<int> e2(1000000);
vector<int> d(1000000);
vector<bool> b(1000000);

int f(int from){
    if(b[from]) return -1;
    if(d[from]) return d[from];
    b[from]=true;
    int to;
    to = e1[from];
    int max=0;
    if(to!=0){
        int now=f(to);
        if(now<0) return now;
        if(now>max) max=now;
    }
    to = e2[from];
    if(to!=0){
        int now=f(to);
        if(now<0) return now;
        if(now>max) max=now;
    }
    b[from]=false;
    return d[from]=max+1;
}

int main(){
    n=nextint();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            a[i][j]=nextint()-1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-2; j++){
            int from = p(i, a[i][j]);
            int to = p(i, a[i][j+1]);
            if(e1[from]==0){
                e1[from]=to;
            }else if(e2[from]==0){
                e2[from]=to;
            }else{
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        int from = p(i, a[i][0]);
        int now=f(from);
        if(now<0){
            ans=-1;
            break;
        }
        if(now>ans) ans=now;
    }
    cout << ans << endl;
}
// 
