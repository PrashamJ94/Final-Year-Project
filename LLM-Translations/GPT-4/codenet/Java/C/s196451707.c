#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int g[n+1][n+1];
    
    for (int i = 0; i < n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            g[u][v] = 1;
        }
    }
    
    int d[n+1];
    for (int i = 0; i <= n; i++) {
        d[i] = -1;
    }
    int que[n * n];
    int front = 0, rear = 0;
    que[rear++] = 1;
    d[1] = 0;
    while (front != rear) {
        int top = que[front++];
        for (int j = 1; j <= n; j++) {
            if (g[top][j] == 1 && d[j] == -1) {
                que[rear++] = j;
                d[j] = d[top] + 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, d[i]);
    }
    
    return 0;
}

// 
