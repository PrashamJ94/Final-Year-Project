
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int id;
    int to;
} Edge;

int n;
Edge** g;
int* ans;

void dfs(int to, int color, int parents) {
    int k = 1;
    for (int i = 0; i < n; i++) {
        if (g[to][i].to == parents) continue;
        if (k == color) k++;
        ans[g[to][i].id] = k;
        dfs(g[to][i].to, k, to);
        k++;
    }
}

int main() {
    scanf("%d", &n);
    g = malloc(n * sizeof(Edge*));
    ans = malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        g[i] = malloc(n * sizeof(Edge));
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a][i].id = i;
        g[a][i].to = b;
        g[b][i].id = i;
        g[b][i].to = a;
    }
    dfs(0, -1, -1);
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] > max) max = ans[i];
    }
    printf("%d\n", max);
    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", ans[i]);
    }
    for (int i = 0; i < n; i++) {
        free(g[i]);
    }
    free(g);
    free(ans);
    return 0;
}
/* //End of Code */

Please note that this C code performs a similar function to the provided Java code, but the two programming languages are fundamentally different in many ways, including memory management, variable declaration, and input/output handling. Therefore, the C code is not a direct translation of the Java code, but it should perform the same tasks within the constraints of the C language.
