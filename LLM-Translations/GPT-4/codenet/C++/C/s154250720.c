#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        int maps[n+1];
        int num[n+1];
        for(int i=1; i<=n; i++) {
            scanf("%d",&maps[i]);
            num[i]=maps[i];
        }
        qsort(maps+1, n, sizeof(int), compare);
        int m=n/2;
        for(int i=1; i<=n; i++) {
            if(num[i]<=maps[m])
                printf("%d\n",maps[m+1]);
            else
                printf("%d\n",maps[m]);

        }
    }
    return 0;
}
// 
