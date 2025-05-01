#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N, max = 0, output = 0;
    scanf("%d", &N);

    int *list = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < N; i++){
        if(max <= list[i]){
            max = list[i];
            output++;
        }
    }

    printf("%d\n", output);

    free(list);
    return 0;
}
//
