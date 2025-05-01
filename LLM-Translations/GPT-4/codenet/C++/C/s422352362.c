#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>

long long a[200005];
long long pre[200005];
long long last[200005];

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    
    long long sumpre = 0, sumlast = 0;
    
    for(int i = 1; i < n; i++){
        sumpre = sumpre + a[i];
        pre[i] = sumpre;
    }
    
    for(int i = n; i > 1; i--){
        sumlast = sumlast + a[i];
        last[i] = sumlast;
    }
    
    long long d = LLONG_MAX;
    
    for(int i = 1; i < n; i++){
        d = (abs(pre[i] - last[i + 1]) < d) ? abs(pre[i] - last[i + 1]) : d;
    }
    
    printf("%lld\n", d);

    return 0;
}
// 
