#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b){
   return (*(int*)b - *(int*)a);
}

char* mainFunc(){
    int N;
    scanf("%d", &N);
    int* S = (int *)malloc(N * sizeof(int));
    for(int i=0; i<N; i++){
        scanf("%d", &S[i]);
    }
    
    qsort(S, N, sizeof(int), compare);
    int* flag = (int *)malloc(N * sizeof(int));
    for(int i=0; i<N; i++){
        flag[i] = 1;
    }
    
    int* cur = (int *)malloc(N * sizeof(int));
    cur[0] = S[0];
    flag[0] = 0;
    
    for(int i=0; i<N; i++){
        int j=0;
        int jM = sizeof(cur)/sizeof(cur[0]);
        for(int k=0; k<N; k++){
            if(flag[k] && S[k] < cur[j]){
                cur[j+1] = S[k];
                j++;
                flag[k] = 0;
                if(j==jM){
                    break;
                }
            }
        }
        if(j != jM){
            return "No";
        }
        qsort(cur, sizeof(cur)/sizeof(cur[0]), sizeof(int), compare);
    }
    return "Yes";
}

int main(){
    printf("%s", mainFunc());
    return 0;
}
// End of Code
