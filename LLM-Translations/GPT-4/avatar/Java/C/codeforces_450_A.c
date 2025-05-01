#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear, size, capacity;
} Queue;

Queue *create_queue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int is_empty(Queue *queue) {
    return (queue->size == 0);
}

void enqueue(Queue *queue, int item) {
    if (queue->size == queue->capacity) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) return -1;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue *queue) {
    if (is_empty(queue)) return -1;
    return queue->arr[queue->front];
}

int main() {
    int n, m, i, ans = 0;
    scanf("%d %d", &n, &m);
    
    Queue *q1 = create_queue(n);
    Queue *q2 = create_queue(n);
    
    for (i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        enqueue(q1, num);
        enqueue(q2, i);
    }
    
    while (!is_empty(q1)) {
        if (front(q1) <= m) {
            dequeue(q1);
            ans = dequeue(q2);
        } else if (front(q1) > m) {
            int x = dequeue(q1);
            int val = x - m;
            enqueue(q1, val);
            int val2 = dequeue(q2);
            enqueue(q2, val2);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
// //End of Code
