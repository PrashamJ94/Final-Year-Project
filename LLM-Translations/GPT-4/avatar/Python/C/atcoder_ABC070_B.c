#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
    int A[4];
    for(int i=0; i<4; i++)
        scanf("%d", &A[i]);

    if(A[1] <= A[2] || A[3] <= A[0])
        printf("0\n");
    else {
        qsort(A, 4, sizeof(int), compare);
        printf("%d\n", A[2] - A[1]);
    }

    return 0;
}

/* End of Code */
