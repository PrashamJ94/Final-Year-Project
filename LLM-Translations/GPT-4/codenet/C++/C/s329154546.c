#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

int L,N;

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main(){
    scanf("%d %d", &N, &L);
    char S[N][L+1];
    rep(i,N) scanf("%s", S[i]);
    qsort(S, N, sizeof(S[0]), compare);
    rep(i,N) printf("%s", S[i]);
    printf("\n");
    return 0;
}

// 
