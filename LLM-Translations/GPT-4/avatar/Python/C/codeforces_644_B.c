#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task {
    int time;
    int duration;
    int index;
} Task;

typedef struct Queue {
    Task* tasks;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->tasks = (Task*) malloc(queue->capacity * sizeof(Task));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Task task) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->tasks[queue->rear] = task;
    queue->size = queue->size + 1;
}

Task dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        Task task = {0, 0, 0};
        return task;
    }
    Task task = queue->tasks[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return task;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    Queue* remaining = createQueue(b);
    int finish_time = 0;
    int* result = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        result[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        int time, duration;
        scanf("%d %d", &time, &duration);
        Task task = {time, duration, i};
        if(task.time > finish_time && isEmpty(remaining)) {
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if(task.time >= finish_time && !isEmpty(remaining)) {
                Task task_to_run = dequeue(remaining);
                finish_time = (task_to_run.time > finish_time ? task_to_run.time : finish_time) + task_to_run.duration;
                result[task_to_run.index] = finish_time;
            }
            if(!isFull(remaining)) {
                enqueue(remaining, task);
            } else {
                result[i] = -1;
            }
        }
    }
    while(!isEmpty(remaining)) {
        Task task_to_run = dequeue(remaining);
        finish_time = (task_to_run.time > finish_time ? task_to_run.time : finish_time) + task_to_run.duration;
        result[task_to_run.index] = finish_time;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    free(remaining->tasks);
    free(remaining);
    return 0;
}

// End of Code.
