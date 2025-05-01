#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int len;
    int capacity;
} heap;

heap* create_heap(int capacity) {
    heap* h = (heap*)malloc(sizeof(heap));
    h->data = (int*)malloc(sizeof(int) * capacity);
    h->len = 0;
    h->capacity = capacity;
    return h;
}

void push(heap* h, int value) {
    if (h->len == h->capacity) {
        h->capacity *= 2;
        h->data = (int*)realloc(h->data, sizeof(int) * h->capacity);
    }
    h->data[h->len] = value;
    int i = h->len;
    h->len++;
    while (i > 0 && h->data[(i - 1) / 2] > h->data[i]) {
        int temp = h->data[i];
        h->data[i] = h->data[(i - 1) / 2];
        h->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int pop(heap* h) {
    int ret = h->data[0];
    h->len--;
    h->data[0] = h->data[h->len];
    int i = 0;
    while (true) {
        int l = i * 2 + 1;
        if (l >= h->len) break;
        int r = i * 2 + 2;
        int j = l;
        if (r < h->len && h->data[r] < h->data[l]) {
            j = r;
        }
        if (h->data[i] <= h->data[j]) break;
        int temp = h->data[i];
        h->data[i] = h->data[j];
        h->data[j] = temp;
        i = j;
    }
    return ret;
}

int main() {
    int q;
    scanf("%d", &q);
    heap* p1 = create_heap(q);
    heap* p2 = create_heap(q);
    int sum_b = 0, sum_p1 = 0, sum_p2 = 0;
    for (int _ = 0; _ < q; _++) {
        int ql0, ql1, ql2;
        scanf("%d", &ql0);
        if (ql0 == 2) {
            if (p1->len == p2->len) {
                printf("%d %d\n", -pop(p2), sum_p1 - p1->len * -top(p2) + p2->len * -top(p2) - sum_p2 + sum_b);
            } else {
                printf("%d %d\n", pop(p1), sum_p1 - p1->len * top(p1) + p2->len * top(p1) - sum_p2 + sum_b);
            }
        } else {
            scanf("%d %d", &ql1, &ql2);
            sum_b += ql2;
            if (p1->len == 0 || ql1 >= p1->data[0]) {
                push(p1, ql1);
                sum_p1 += ql1;
            } else {
                push(p2, -ql1);
                sum_p2 += ql1;
            }
            if (p1->len < p2->len) {
                int k = pop(p2);
                push(p1, -k);
                sum_p2 += k;
                sum_p1 -= k;
            }
            if (p1->len - 1 > p2->len) {
                int k = pop(p1);
                push(p2, -k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
    free(p1->data);
    free(p1);
    free(p2->data);
    free(p2);
    return 0;
}
// End of Code

//This translated code in C language uses a binary heap data structure (also known as a priority queue) to perform operations similar to the Python code. The C code differs slightly as it uses a struct to create a heap and functions to manipulate the heap. In C, memory management is manually done, hence the need to free the allocated memory at the end.
