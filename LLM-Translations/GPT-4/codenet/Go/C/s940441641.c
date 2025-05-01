
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define Inf (1 << 30)

int H, W, K, x1, y1, x2, y2;
char **c;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int toID(int x, int y, int dir) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int *x, int *y, int *dir) {
    *x = id / 4 % W;
    *y = id / 4 / W;
    *dir = id % 4;
}

typedef struct {
    int cost, id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} Heap;

void heap_push(Heap *h, State v);
State heap_pop(Heap *h);

int main() {
    scanf("%d%d%d", &H, &W, &K);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--;
    int tmp = x1; x1 = y1; y1 = tmp;
    tmp = x2; x2 = y2; y2 = tmp;

    c = (char **) malloc(H * sizeof(char *));
    for (int y = 0; y < H; y++) {
        c[y] = (char *) malloc((W + 1) * sizeof(char));
        scanf("%s", c[y]);
    }

    int *dist = (int *) malloc(W * H * 4 * sizeof(int));
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = Inf;
    }

    Heap q = {NULL, 0, 0};
    for (int i = 0; i < 4; i++) {
        heap_push(&q, (State){0, toID(x1, y1, i)});
    }
    while (q.size > 0) {
        State now = heap_pop(&q);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir);
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[now.id] <= now.cost) {
            continue;
        }
        dist[now.id] = now.cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            heap_push(&q, (State){nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            heap_push(&q, (State){nCost, nID});
        }
    }
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < Inf) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}

void heap_push(Heap *h, State v) {
    if (h->size + 1 > h->capacity) {
        h->capacity = h->capacity > 0 ? h->capacity * 2 : 4;
        h->data = (State *) realloc(h->data, h->capacity * sizeof(State));
    }
    h->data[h->size] = v;
    int i = h->size;
    h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].cost <= h->data[i].cost) {
            break;
        }
        State tmp = h->data[p];
        h->data[p] = h->data[i];
        h->data[i] = tmp;
        i = p;
    }
}

State heap_pop(Heap *h) {
    State ret = h->data[0];
    h->size--;
    h->data[0] = h->data[h->size];
    int i = 0;
    while (true) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if (l >= h->size) {
            break;
        }
        int min = l;
        if (r < h->size && h->data[r].cost < h->data[l].cost) {
            min = r;
        }
        if (h->data[min].cost >= h->data[i].cost) {
            break;
        }
        State tmp = h->data[min];
        h->data[min] = h->data[i];
        h->data[i] = tmp;
        i = min;
    }
    return ret;
}


