#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    
    free(arr);

    return 0;
}
// End of Code


//Please note that in C we need to handle memory allocation and deallocation manually. Also, for sorting an array, we have used the `qsort` function from the `stdlib.h` library. The `compare` function is used to tell `qsort` how to sort the integers. The `malloc` function is used to allocate memory for the array dynamically. After we are done with the array, we free the memory space using the `free` function to prevent memory leaks.
