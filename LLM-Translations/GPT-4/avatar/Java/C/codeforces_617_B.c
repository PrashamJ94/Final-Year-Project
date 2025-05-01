#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;
    int input;

    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int arr_size = 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &input);
        if (input == 1) {
            arr[arr_size++] = i;
        }
    }

    if (arr_size == 0) {
        printf("0\n");
    } else {
        long long result = 1;
        for (i = 1; i < arr_size; i++) {
            result *= arr[i] - arr[i - 1];
        }
        printf("%lld\n", result);
    }

    free(arr);

    return 0;
} // //End of Code
