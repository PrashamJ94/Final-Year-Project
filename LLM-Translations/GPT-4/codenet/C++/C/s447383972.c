
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)

ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

void write(ll x){
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}

void writeln(ll x){
    write(x);
    puts("");
}

int cmpfunc(const void *a, const void *b){
    return (*(ll*)a - *(ll*)b);
}

const ll N=200010;
ll a[N],q[N],n,tot;
int main(){
    n=read();
    For(i,1,n) a[i]=read();
    qsort(a+1, n, sizeof(ll), cmpfunc);
    For(i,1,n) if (a[i]==a[i+1]) q[++tot]=a[i],i++;
    writeln(q[tot]*q[tot-1]);
    return 0;
}

// 
