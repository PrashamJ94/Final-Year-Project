#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int arr_size);

int main(void) {

    int iNum = 0;
    scanf("%d", &iNum);
    int *arr = (int *)malloc(iNum * sizeof(int));
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, iNum);

    free(arr);
    return 0;
}

void sort(int *arr, int arr_size) {

    for (int i = 0; i < arr_size; i++) {

        if (i != 0) {

            int iIntValue = arr[i];
            int j = i - 1;
            while ((j >= 0) && (arr[j] > iIntValue)) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = iIntValue;
        }

        for (int k = 0; k < arr_size; k++) {
            printf("%d", arr[k]);
            if (k != arr_size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
// 
