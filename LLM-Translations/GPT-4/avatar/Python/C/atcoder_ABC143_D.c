#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binary_search_left(int arr[], int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int binary_search_right(int arr[], int low, int high, int key) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n, i, j, ans = 0;
    scanf("%d", &n);
    int l[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), compare);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int a = l[i], b = l[j];
            int right = binary_search_left(l, 0, n, a + b);
            int left = binary_search_right(l, 0, n, a > b ? a - b : b - a);
            int tmp = right - left > 0 ? right - left : 0;
            if (left <= i && i < right)
                tmp--;
            if (left <= j && j < right)
                tmp--;
            ans += tmp;
        }
    }
    printf("%d\n", ans / 3);
    return 0;
}

//End of Code.
