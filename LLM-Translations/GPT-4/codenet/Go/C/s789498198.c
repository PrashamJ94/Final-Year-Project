#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair *v;
    int size;
} Queue;

void push(Queue *q, Pair v) {
    q->v = realloc(q->v, (q->size + 1) * sizeof(Pair));
    q->v[q->size] = v;
    q->size++;
}

Pair pop(Queue *q) {
    Pair r = q->v[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->v[i] = q->v[i + 1];
    }
    q->size--;
    q->v = realloc(q->v, q->size * sizeof(Pair));
    return r;
}

Pair front(Queue q) {
    return q.v[0];
}

bool empty(Queue q) {
    return q.size == 0;
}

int digits(int x) {
    int count = 0;
    while (x != 0) {
        x /= 10;
        count++;
    }
    return count;
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int abs(int x) {
    return x >= 0 ? x : -x;
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
        return 0;
    }
    printf("IMPOSSIBLE\n");

    return 0;
}

// 
