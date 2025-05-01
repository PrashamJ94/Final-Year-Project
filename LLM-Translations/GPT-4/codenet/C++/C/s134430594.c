#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct Ban {
    int l;
    int r;
    int val;
} Ban;

const int LIM = 20; 
const int N = 2e5 + 7;

int mn[LIM][N];
int pw[N];

void init(int a[], int n) {
    for (int i = 0; i < n; i++) {
        mn[0][i] = a[i]; 
    }
    for (int i = 0; i + 1 < LIM; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            mn[i + 1][j] = fmax(mn[i][j], mn[i][j + (1 << i)]);
        }
    }
    pw[1] = 0;
    for (int i = 2; i < N; i++) {
        pw[i] = pw[i / 2] + 1;
    }
} 

int get(int l, int r) {
    r++;
    int p = pw[r - l];
    return fmin(mn[p][l], mn[p][r - (1 << p)]);
}

int main() {
    int n;
    scanf("%lld", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int dl[n];
    for (int i = 0; i < n; i++) {
        if (a[i] > i) {
            printf("-1\n");
            return 0;
        }
        dl[i] = i - a[i];
    }
    int ans = 0;
    int bans_size = 0;
    Ban* bans = NULL;
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
        bans_size++;
        bans = (Ban*)realloc(bans, bans_size * sizeof(Ban));
        bans[bans_size - 1].l = r - a[r];
        bans[bans_size - 1].r = r;
        bans[bans_size - 1].val = r - a[r];
    }
    init(dl, n);
    for (int i = 0; i < bans_size; i++) {
        if (get(bans[i].l, bans[i].r) > bans[i].val) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", ans);
    free(bans);
    return 0;
}
// 
