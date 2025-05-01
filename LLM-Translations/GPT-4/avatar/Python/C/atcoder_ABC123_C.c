#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int N, min;
    int A[5];

    scanf("%d", &N);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
        if(i == 0 || A[i] < min) {
            min = A[i];
        }
    }
    printf("%d\n", (int)ceil((double)N/min) + 4);

    return 0;
}

//End of Code
