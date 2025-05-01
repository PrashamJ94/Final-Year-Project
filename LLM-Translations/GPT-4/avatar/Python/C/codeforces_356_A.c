#include<stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int out[n], comp[n];
    for(int i = 0; i < n; i++) {
        out[i] = 0;
        comp[i] = i + 2;
    }
    for(int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        int t = l;
        while(t <= r) {
            int next_val = comp[t - 1];
            if(out[t - 1] == 0 && t != x) {
                out[t - 1] = x;
            }
            comp[t - 1] = (t >= x) ? r + 1 : x;
            t = next_val;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    return 0;
}

// End of Code
