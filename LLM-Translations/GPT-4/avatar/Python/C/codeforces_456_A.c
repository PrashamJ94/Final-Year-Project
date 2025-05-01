
#include <stdio.h>
#include <stdlib.h>

// Structure for Pair
struct Pair {
    int first, second;
};

// Function for comparison in descending order
int compare(const void* a, const void* b) {
    return (((struct Pair*)b)->first) - (((struct Pair*)a)->first);
}

int main() {
    int n, i;
    scanf("%d", &n);
    struct Pair m[n];
    
    // Taking input
    for(i = 0; i < n; i++) {
        scanf("%d%d", &m[i].first, &m[i].second);
    }
    
    // Sorting
    qsort(m, n, sizeof(struct Pair), compare);
    
    struct Pair a = m[0];
    
    for(i = 1; i < n; i++) {
        if(m[i].second > a.second) {
            printf("Happy Alex\n");
            return 0;
        }
        a = m[i];
    }
    
    printf("Poor Alex\n");
    return 0;
}
// End of Code


