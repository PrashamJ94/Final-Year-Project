#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int a;
    int b;
} Job;

int compare(const void * a, const void * b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->a != jobB->a) return jobA->a - jobB->a;
    return jobB->b - jobA->b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Job jobs[N];
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].a, &jobs[i].b);
    }
    qsort(jobs, N, sizeof(Job), compare);
    int cnt = 0;
    int jobQ[N];
    int top = -1;
    int j = 0;
    for(int i = 0; i < M; i++) {
        while(j < N && jobs[j].a <= i+1) {
            jobQ[++top] = jobs[j++].b;
        }
        if(top >= 0) {
            int max = 0, max_index = 0;
            for(int k = 0; k <= top; k++) {
                if(jobQ[k] > max) {
                    max = jobQ[k];
                    max_index = k;
                }
            }
            cnt += max;
            jobQ[max_index] = jobQ[top--];
        }
    }
    printf("%d\n", cnt);
    return 0;
} 
/* //End of Code */
