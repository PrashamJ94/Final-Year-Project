
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct deque {
    char *front, *back;
    int front_size, back_size;
} deque;

bool isEmptyFront(deque *deq) {
    return deq->front_size == 0;
}

bool isEmptyBack(deque *deq) {
    return deq->back_size == 0;
}

void pushBack(deque *deq, char v) {
    deq->back[deq->back_size++] = v;
}

void pushFront(deque *deq, char v) {
    deq->front[deq->front_size++] = v;
}

bool popBack(deque *deq, char *v) {
    bool r = true;
    if (!isEmptyBack(deq)) {
        *v = deq->back[--deq->back_size];
    } else if (!isEmptyFront(deq)) {
        *v = deq->front[--deq->front_size];
    } else {
        r = false;
    }
    return r;
}

bool popFront(deque *deq, char *v) {
    bool r = true;
    if (!isEmptyFront(deq)) {
        *v = deq->front[--deq->front_size];
    } else if (!isEmptyBack(deq)) {
        *v = deq->back[--deq->back_size];
    } else {
        r = false;
    }
    return r;
}

char get(deque *deq, int idx) {
    int tot = deq->front_size + deq->back_size;
    char v = 0;
    if (idx < tot) {
        if (idx < deq->front_size) {
            v = deq->front[deq->front_size - 1 - idx];
        } else {
            v = deq->back[idx - deq->front_size];
        }
    }
    return v;
}

typedef struct op {
    bool rev, front;
    char c;
} op;

void reverse_str(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main() {
    char S[100010];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    op ops[200010];
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = true;
        } else {
            int f;
            scanf("%d %c", &f, &ops[i].c);
            if (f == 1) {
                ops[i].front = true;
            }
        }
    }
    int sum[200010];
    sum[Q] = 0;
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }
    if (sum[0] % 2 == 1) {
        reverse_str(S);
    }
    deque deq;
    deq.front = (char *)malloc(100010 * sizeof(char));
    deq.back = (char *)malloc(100010 * sizeof(char));
    deq.front_size = deq.back_size = 0;
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    pushBack(&deq, ops[i].c);
                } else {
                    pushFront(&deq, ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    pushFront(&deq, ops[i].c);
                } else {
                    pushBack(&deq, ops[i].c);
                }
            }
        }
    }
    for (int i = deq.front_size - 1; i >= 0; i--) {
        printf("%c", deq.front[i]);
    }
    printf("%s", S);
    for (int i = 0; i < deq.back_size; i++) {
        printf("%c", deq.back[i]);
    }
    printf("\n");
    free(deq.front);
    free(deq.back);
    return 0;
}


