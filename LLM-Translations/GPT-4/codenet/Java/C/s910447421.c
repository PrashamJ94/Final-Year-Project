#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int ans = 100;
int** balls;
int N;
bool* taken;

int min(int a, int b) {return a < b ? a : b;}
long GCD(long a, long b) {
    if (a==0||b==0) return a > b ? a : b;
    return GCD(min(a,b), (a > b ? a : b) % (a < b ? a : b));
}

int check(int p, int q) {
    int ret = 0;
    while (true) {
        bool added=false;
        int start = 0;
        int x = -1;
        int y = -1; 
        for (int i = 0; i < N; i++) {
            if (!taken[i]) {
                added=true;
                ret++;
                start=i;
                taken[i]=true;
                x=balls[i][0]+p;
                y=balls[i][1]+q;
                break;
            }
        }
        if (!added) break;
        for (int i = start+1; i < N; i++) {
            if (balls[i][0]==x&&balls[i][1]==y) {
                taken[i]=true;
                x+=p;
                y+=q;
            }
        } 
    }
    return ret;
}

void solve() {
    for (int add = 1; add<N; add++) {
        taken = calloc(N, sizeof(bool));
        int p = balls[add][0]-balls[0][0];
        int q = balls[add][1]-balls[0][1];
        ans=min(ans,check(p,q));
        free(taken);
    }
}

int compare(const void *a, const void *b) {
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    return pa[0] - pb[0];
}

int main() {
    scanf("%d", &N);
    ans = N;
    balls = calloc(N, sizeof(int*));
    for (int i = 0; i < N; i++) {
        balls[i] = calloc(2, sizeof(int));
        scanf("%d %d", &balls[i][0], &balls[i][1]);
    }
    qsort(balls, N, sizeof(int*), compare);
    solve();
    for (int i = 0; i < N; i++) {
        int x = balls[i][0];
        int y = balls[i][1];
        balls[i][0]=y;
        balls[i][1]=x;
    }
    qsort(balls, N, sizeof(int*), compare);
    solve();
    printf("%d\n", ans);

    for (int i = 0; i < N; i++) {
        free(balls[i]);
    }
    free(balls);
    return 0;
}
// 
