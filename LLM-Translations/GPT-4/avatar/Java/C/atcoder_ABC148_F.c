#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void add_edge(Node **edges, int a, int b) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = b;
    new_node->next = edges[a];
    edges[a] = new_node;
}

void dfs(int u, int *d, Node **edges) {
    for (Node *nu = edges[u]; nu != NULL; nu = nu->next) {
        if (d[nu->val] == INT_MAX) {
            d[nu->val] = d[u] + 1;
            dfs(nu->val, d, edges);
        }
    }
}

int main() {
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--;
    v--;

    Node **edges = calloc(N, sizeof(Node *));
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        add_edge(edges, a, b);
        add_edge(edges, b, a);
    }

    int *d = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    dfs(u, d, edges);

    int *e = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v] = 0;
    dfs(v, e, edges);

    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    for (int i = 0; i < N; i++) {
        Node *current = edges[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(edges);
    free(d);
    free(e);
    return 0;
}
// //End of Code
