#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define INF 1LL<<60

typedef struct Mon {
    int x, h;
} Mon;

typedef struct Node {
    int x, h;
} Node;

typedef struct Queue {
    Node* arr;
    int size;
} Queue;

int mon_compare(const void* a, const void* b) {
    Mon *mon_a = (Mon *)a;
    Mon *mon_b = (Mon *)b;
    return mon_a->x - mon_b->x;
}

void queue_push(Queue* q, Node v) {
    q->arr = (Node *)realloc(q->arr, (q->size + 1) * sizeof(Node));
    q->arr[q->size] = v;
    q->size++;
}

Node queue_first(Queue* q) {
    return q->arr[0];
}

Node queue_pop(Queue* q) {
    Node res = q->arr[0];
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }
    q->size--;
    q->arr = (Node *)realloc(q->arr, q->size * sizeof(Node));
    return res;
}

bool queue_isEmpty(Queue* q) {
    return q->size == 0;
}

int ceil_div(int a, int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);
    Mon M[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M[i].x, &M[i].h);
    }
    qsort(M, N, sizeof(Mon), mon_compare);

    Queue q;
    q.arr = NULL;
    q.size = 0;
    int ans = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!queue_isEmpty(&q) && queue_first(&q).x < m.x) {
            total -= queue_pop(&q).h;
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil_div(m.h, A);
            ans += count;
            int damage = count * A;
            queue_push(&q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%d\n", ans);

    return 0;
}

// 
