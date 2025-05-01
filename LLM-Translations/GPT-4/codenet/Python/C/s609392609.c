#include <stdio.h>

int main() {
    int n, m, p, x;
    scanf("%d", &n);
    int t[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &p, &x);
        int s = 0;
        for(int j = 0; j < n; j++) {
            if(j == p - 1) {
                s += x;
            } else {
                s += t[j];
            }
        }
        printf("%d\n", s);
    }
    return 0;
}

// 
