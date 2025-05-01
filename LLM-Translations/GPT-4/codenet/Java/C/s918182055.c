#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedList {
    int value;
    struct LinkedList *next;
} LinkedList;

typedef struct PriorityQueue {
    int size;
    int capacity;
    int *data;
} PriorityQueue;

PriorityQueue* create_pqueue(int capacity);
void add(PriorityQueue *pqueue, int value);
int poll(PriorityQueue *pqueue);
bool is_empty(PriorityQueue *pqueue);
void swap(int *a, int *b);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    LinkedList *list[100001] = {0};

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
        node->value = b;
        node->next = list[a];
        list[a] = node;
    }

    int res = 0;
    PriorityQueue *pqueue = create_pqueue(N);
    for (int i = 1; i <= M; i++) {
        LinkedList *cur = list[i];
        while (cur != NULL) {
            add(pqueue, cur->value);
            cur = cur->next;
        }
        if (!is_empty(pqueue)) {
            res += poll(pqueue);
        }
    }

    printf("%d\n", res);
    return 0;
}

PriorityQueue* create_pqueue(int capacity) {
    PriorityQueue *pqueue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pqueue->size = 0;
    pqueue->capacity = capacity;
    pqueue->data = (int *)malloc(capacity * sizeof(int));
    return pqueue;
}

void add(PriorityQueue *pqueue, int value) {
    pqueue->data[pqueue->size] = value;
    int idx = pqueue->size;
    while (idx > 0 && pqueue->data[(idx - 1) / 2] < pqueue->data[idx]) {
        swap(&pqueue->data[(idx - 1) / 2], &pqueue->data[idx]);
        idx = (idx - 1) / 2;
    }
    pqueue->size++;
}

int poll(PriorityQueue *pqueue) {
    int result = pqueue->data[0];
    pqueue->data[0] = pqueue->data[--pqueue->size];

    int idx = 0;
    while (true) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;

        if (left >= pqueue->size) break;

        int max_child = left;
        if (right < pqueue->size && pqueue->data[left] < pqueue->data[right]) {
            max_child = right;
        }

        if (pqueue->data[idx] >= pqueue->data[max_child]) break;

        swap(&pqueue->data[idx], &pqueue->data[max_child]);
        idx = max_child;
    }

    return result;
}

bool is_empty(PriorityQueue *pqueue) {
    return pqueue->size == 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//
