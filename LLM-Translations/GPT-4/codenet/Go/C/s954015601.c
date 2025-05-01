
#include <stdio.h>
#include <stdlib.h>

int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a * 100000 + b;
}

int main() {
    int N, a, b, K = -1;
    scanf("%d", &N);

    int ab[N-1][2];
    int *edges[N];
    for (int i = 0; i < N; i++) {
        edges[i] = (int *) calloc(N, sizeof(int));
    }
    int edges_len[N];

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        ab[i][0] = a;
        ab[i][1] = b;
        edges[a][edges_len[a]++] = b;
        edges[b][edges_len[b]++] = a;
    }

    int *colors = (int *) calloc(N * N, sizeof(int));
    int q[N * 3];
    int q_len = 0;
    q[q_len++] = 0;
    q[q_len++] = -1;
    q[q_len++] = -1;

    while (q_len != 0) {
        int parentNode = q[--q_len];
        int usedColor = q[--q_len];
        int currentNode = q[--q_len];
        int color = 1;
        for (int i = 0; i < edges_len[currentNode]; i++) {
            int childNode = edges[currentNode][i];
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            colors[genid(currentNode, childNode)] = color;
            q[q_len++] = childNode;
            q[q_len++] = color;
            q[q_len++] = currentNode;
            color++;
        }
    }

    for (int i = 0; i < N; i++) {
        int t = edges_len[i];
        if (t > K) {
            K = t;
        }
    }
    printf("%d\n", K);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    for (int i = 0; i < N; i++) {
        free(edges[i]);
    }
    free(colors);

    return 0;
}
// 


