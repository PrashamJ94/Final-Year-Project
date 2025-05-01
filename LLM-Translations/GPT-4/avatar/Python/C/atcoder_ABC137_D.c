
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int day;
    int salary;
}Job;

int compare(const void *a, const void *b){
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->day - jobA->day;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Job jobs[n];
    int salaries[m];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &jobs[i].day, &jobs[i].salary);
    }
    qsort(jobs, n, sizeof(Job), compare);
    int index = 0;
    long long result = 0;
    for(int i = m; i >= 1; i--){
        while(index < n && jobs[index].day >= i){
            salaries[index] = jobs[index].salary;
            index++;
        }
        int max = 0;
        int max_index = 0;
        for(int j = 0; j < index; j++){
            if(salaries[j] > max){
                max = salaries[j];
                max_index = j;
            }
        }
        result += max;
        salaries[max_index] = 0;
    }
    printf("%lld\n", result);
    return 0;
}
/* End of Code */

//This C code does the same thing as the given Python code. It first reads the number of jobs and the maximum number of days from the user. Then it reads the days and salaries for each job. After that, it sorts the jobs in descending order based on the number of days. Then it iterates from the maximum number of days to 1 and for each day, it selects the job with the highest salary that can be done within the remaining days. Finally, it prints the total salary.
