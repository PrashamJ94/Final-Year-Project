#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int priority;
    int data;
} node_t;

typedef struct {
    node_t *nodes;
    int len;
    int size;
} heap_t;

heap_t *create() {
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    h->len = 0;
    h->size = MAX_SIZE;
    h->nodes = (node_t *)malloc(sizeof(node_t) * h->size);
    return h;
}

void push(heap_t *h, int priority, int data) {
    if (h->len + 1 >= h->size) {
        h->size = h->size ? h->size*2 : 4;
        h->nodes = (node_t *)realloc(h->nodes, sizeof(node_t) * h->size);
    }
    int i = h->len + 1;
    int j = i / 2;
    while (i > 1 && h->nodes[j].priority > priority) {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j / 2;
    }
    h->nodes[i].priority = priority;
    h->nodes[i].data = data;
    h->len++;
}

node_t pop(heap_t *h) {
    int i, j, k;
    if (!h->len) {
        return (node_t){-1, -1};
    }
    node_t min = h->nodes[1];
    h->nodes[1] = h->nodes[h->len];
    h->len--;
    i = 1;
    while (1) {
        k = i;
        j = 2 * i;
        if (j <= h->len && h->nodes[j].priority < h->nodes[k].priority) {
            k = j;
        }
        if (j + 1 <= h->len && h->nodes[j + 1].priority < h->nodes[k].priority) {
            k = j + 1;
        }
        if (k == i) {
            break;
        }
        node_t tmp = h->nodes[i];
        h->nodes[i] = h->nodes[k];
        h->nodes[k] = tmp;
        i = k;
    }
    return min;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    bool flag[N];
    int parity[N], degs[N];
    heap_t *Q = create();
    for (int i = 0; i < N; i++) {
        flag[i] = false;
        parity[i] = 0;
        degs[i] = 0;
        push(Q, 0, i);
    }
    if (M % 2 != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        degs[a]++;
        degs[b]++;
        push(Q, degs[a], a);
        push(Q, degs[b], b);
    }
    while (Q->len > 0) {
        node_t node = pop(Q);
        int u = node.data;
        if (flag[u]) {
            continue;
        }
        flag[u] = true;
        for (int i = 0; i < N; i++) {
            if (i != u && !flag[i]) {
                printf("%d %d\n", u + 1, i + 1);
                flag[i] = true;
                break;
            }
        }
    }
    return 0;
}

// End of Code

