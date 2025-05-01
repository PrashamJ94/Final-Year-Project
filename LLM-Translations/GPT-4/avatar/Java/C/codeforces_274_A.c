#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() {
    int n;
    long k;
    scanf("%d %ld", &n, &k);
    
    long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    
    qsort(arr, n, sizeof(long), compare);
    
    bool set[n];
    for (int i = 0; i < n; i++) {
        set[i] = false;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            count++;
            set[i] = true;
        } else {
            bool found = false;
            for (int j = 0; j < n && arr[j] < arr[i] / k; j++) {
                if (set[j] && arr[j] == arr[i] / k) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                count++;
                set[i] = true;
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}

// //End of Code.
