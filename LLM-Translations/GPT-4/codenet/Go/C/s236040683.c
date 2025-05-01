
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int* to;
    int size;
} Node;

int getInt() {
    int i;
    if (scanf("%d", &i) != 1) {
        perror("Error: Input conversion error");
        exit(1);
    }
    return i;
}

char* getString() {
    char* str = malloc(100);
    if (scanf("%s", str) != 1) {
        perror("Error: Input conversion error");
        exit(1);
    }
    return str;
}

int main() {
    int N = getInt();
    int M = getInt();
    Node* n = malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        n[i].to = malloc(0);
        n[i].size = 0;
    }

    for (int i = 0; i < M; i++) {
        int from = getInt() - 1;
        int to = getInt() - 1;
        n[from].to = realloc(n[from].to, (n[from].size + 1) * sizeof(int));
        n[from].to[n[from].size++] = to;
        n[to].to = realloc(n[to].to, (n[to].size + 1) * sizeof(int));
        n[to].to[n[to].size++] = from;
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", n[i].size);
    }

    for (int i = 0; i < N; i++) {
        free(n[i].to);
    }
    free(n);

    return 0;
}

// 
