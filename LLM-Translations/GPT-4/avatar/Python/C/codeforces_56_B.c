#include <stdio.h>

int main() {
    int N, i, mn, mx;
    scanf("%d", &N);
    int A[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    mn = N + 1;
    mx = -1;
    for(i = 0; i < N; i++) {
        if((i + 1) != A[i]) {
            mn = (mn < i) ? mn : i;
            mx = (mx > i) ? mx : i;
        }
    }
    if(mx == -1) {
        printf("0 0\n");
    } else {
        int temp, start = mn, end = mx;
        while(start < end) {
            temp = A[start]; 
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
        int sorted = 1;
        for(i = 1; i < N; i++) {
            if(A[i-1] > A[i]) {
                sorted = 0;
                break;
            }
        }
        if(sorted) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }
    }
    return 0;
} // End of Code
