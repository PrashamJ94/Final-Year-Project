#include <stdio.h>
#include <stdlib.h>

// Define a structure for the pair (index, value)
typedef struct {
    int index;
    int value;
} Pair;

// Comparator function for qsort
int compare (const void * a, const void * b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return ( pairA->value - pairB->value );
}

int main() {
    // Read N
    int N;
    scanf("%d", &N);
    
    // Read A and initialize A_
    Pair A_[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &(A_[i].value));
        A_[i].index = i + 1;
    }
    
    // Sort A_
    qsort(A_, N, sizeof(Pair), compare);
    
    // Print A_
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A_[i].index);
    }
    printf("%d", A_[N - 1].index);
    
    return 0;
} // End of Code


