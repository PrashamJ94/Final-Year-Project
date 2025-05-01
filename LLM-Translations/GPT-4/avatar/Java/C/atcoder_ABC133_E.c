#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long pattern;
    int index;
    int children_count;
    int *children;
    int parent;
} Node;

void setParent(Node *node, int K, int parent, int use, Node *nodes) {
    node->pattern = K - use;
    node->parent = parent;
    int count = 1;
    if (parent != -1) {
        count++;
    }
    for (int i = 0; i < node->children_count; i++) {
        int n = node->children[i];
        if (n == node->parent) {
            continue;
        }
        setParent(&nodes[n], K, node->index, count, nodes);
        count++;
    }
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);

    Node *nodes = (Node *)malloc(N * sizeof(Node));

    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children_count = 0;
        nodes[i].children = NULL;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;

        nodes[a].children_count++;
        nodes[a].children = (int *)realloc(nodes[a].children, nodes[a].children_count * sizeof(int));
        nodes[a].children[nodes[a].children_count - 1] = b;

        nodes[b].children_count++;
        nodes[b].children = (int *)realloc(nodes[b].children, nodes[b].children_count * sizeof(int));
        nodes[b].children[nodes[b].children_count - 1] = a;
    }

    setParent(&nodes[0], K, -1, 0, nodes);

    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % 1000000007;
    }

    printf("%ld\n", patterns);

    for (int i = 0; i < N; i++) {
        free(nodes[i].children);
    }
    free(nodes);
}

int main() {
    solve();
    return 0;
}

/* //End of Code */
