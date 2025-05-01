#include <stdio.h>

int main() {
    int n, max = 0, min = 10000;
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (max < array[i]) {
            max = array[i];
        }

        if (min > array[i]) {
            min = array[i];
        }
    }
    printf("%d\n", max - min);

    return 0;
}
// 
