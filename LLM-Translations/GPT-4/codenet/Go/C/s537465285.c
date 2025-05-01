#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool Bipartite(char** S, int N) {
    int* D = (int*)malloc(N * sizeof(int));
    memset(D, 0, N * sizeof(int));
    D[0] = 1;
    int* Q = (int*)malloc(N * sizeof(int));
    bool ret = true;
    int pos = 1;
    for (int i = 0; i < N; i++) {
        if (!ret) break;
        int q = Q[i];
        for (int j = 0; j < N; j++) {
            if (S[q][j] == '0') {
                continue;
            }
            if (D[j] == 0) {
                D[j] = D[q] + 1;
                Q[pos] = j;
                pos++;
                continue;
            }
            if (D[j] % 2 == D[q] % 2) {
                ret = false;
                break;
            }
        }
    }
    free(D);
    free(Q);
    return ret;
}

int WarshallFloyd(char** S, int N) {
    int** G = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        G[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (S[i][j] == '0') {
                G[i][j] = N;
            } else {
                G[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans < G[i][j]) ans = G[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        free(G[i]);
    }
    free(G);
    return ans + 1;
}

int main() {
    int N;
    scanf("%d", &N);
    char** S = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        S[i] = (char*)malloc((N + 1) * sizeof(char));
        scanf("%s", S[i]);
    }
    if (!Bipartite(S, N)) {
        printf("-1\n");
    } else {
        printf("%d\n", WarshallFloyd(S, N));
    }
    for (int i = 0; i < N; i++) {
        free(S[i]);
    }
    free(S);
    return 0;
}
// 
