#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct task {
    char name[20];
    int time;
} Task;

int main()
{
    int n, q;
    int elaps = 0;
    int front = 0, rear = 0;

    scanf("%d %d", &n, &q);

    Task *Q = (Task *) malloc(n * sizeof(Task));

    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time);
        rear++;
    }

    while(front != rear) {
        Task p = Q[front]; 
        front = (front + 1) % n;
        if(p.time <= q) {
            elaps += p.time;
            printf("%s %d\n", p.name, elaps);
        }
        else {
            p.time -= q;
            elaps += q;
            Q[rear] = p;
            rear = (rear + 1) % n;
        }
    }
    free(Q);
    return 0;
}
// 
