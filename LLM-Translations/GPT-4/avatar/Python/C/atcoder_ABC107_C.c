#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int check(int k, int *lst_p, int *lst_m, int lastx, int lasty) {
    int ans = 1000000000;
    for(int j = 0; j <= k; j++) {
        if(j > lastx || k - j > lasty) {
            continue;
        } else {
            int p = (j == 0) ? 0 : lst_p[j - 1];
            int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];
            ans = (2 * p + abs(m) < ans) ? 2 * p + abs(m) : ans;
            ans = (p + 2 * abs(m) < ans) ? p + 2 * abs(m) : ans;
        }
    }
    return ans;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int lst[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
    }
    int lst_p[N], lst_m[N];
    int p = 0, m = 0;
    for(int i = 0; i < N; i++) {
        if(lst[i] == 0) {
            K--;
        } else if(lst[i] > 0) {
            lst_p[p++] = lst[i];
        } else {
            lst_m[m++] = lst[i];
        }
    }
    qsort(lst_p, p, sizeof(int), cmpfunc);
    qsort(lst_m, m, sizeof(int), cmpfunc);
    printf("%d\n", check(K, lst_p, lst_m, p, m));
    return 0;
} //End of Code
