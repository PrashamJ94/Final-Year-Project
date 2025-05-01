#include<stdio.h>
#include<math.h>

int task4(int A, int B, int n) {
    int X;
    for(X = -1000; X <= 1000; X++) {
        if(A * pow(X, n) == B) {
            return X;
        }
    }
    return -1; // Returning -1 to indicate "No solution"
}

int main() {
    int A, B, n, result;
    scanf("%d %d %d", &A, &B, &n);
    result = task4(A, B, n);
    if(result != -1) {
        printf("%d", result);
    } else {
        printf("No solution");
    }
    return 0;
} // End of Code
