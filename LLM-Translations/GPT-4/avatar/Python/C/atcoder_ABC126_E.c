#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if(q->front == NULL) return -1;
    Node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    if(q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void addEdge(Node* edge[], int u, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = edge[u];
    edge[u] = newNode;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Node* edge[N];
    for(int i = 0; i < N; i++) edge[i] = NULL;
    for(int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        X--; Y--; Z--;
        addEdge(edge, X, Y);
        addEdge(edge, Y, X);
    }
    bool used[N];
    for(int i = 0; i < N; i++) used[i] = false;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(!used[i]) {
            ans++;
            Queue queue;
            queue.front = queue.rear = NULL;
            enqueue(&queue, i);
            while(!isQueueEmpty(&queue)) {
                int node = dequeue(&queue);
                used[node] = true;
                for(Node* nextNode = edge[node]; nextNode != NULL; nextNode = nextNode->next) {
                    if(!used[nextNode->data]) {
                        enqueue(&queue, nextNode->data);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

// End of Code
