C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining adjacency list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* AdjList[100000];
bool visited[100000];
int color[100000];
long one = 0;
long bipartite = 0;
long count = 0;
bool mujun = false;

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node* node = createNode(v);
    node->next = AdjList[u];
    AdjList[u] = node;

    node = createNode(u);
    node->next = AdjList[v];
    AdjList[v] = node;
}

int dfs(int a, int c) {
    if (visited[a]) {
        if (color[a] >= 0 && color[a] != c) mujun = true;
        return 0;
    }
    visited[a] = true;
    color[a] = c;
    int total = 1;
    for (struct Node* node = AdjList[a]; node != NULL; node = node->next) {
        total += dfs(node->data, 1 - c);
    }
    return total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        AdjList[i] = NULL;
        visited[i] = false;
        color[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        addEdge(u, v);
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        count++;
        mujun = false;
        int kind = dfs(i, 0);
        if (kind == 1) one++;
        else if (!mujun) bipartite++;
    }
    long total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;
    printf("%ld\n", total);
    return 0;
}
/* End of code */


