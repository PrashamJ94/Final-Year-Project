#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void cutRibbon() {
    int length;
    int arr[3];
    scanf("%d %d %d %d", &length, &arr[0], &arr[1], &arr[2]);

    for (int i = 1; i < 3; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }

    if (length % arr[0] == 0) {
        printf("%d\n", length / arr[0]);
        return;
    }

    int ans = 0;
    if (arr[0] == arr[1]) {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; i++) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                k = check / arr[0];
                ans = max(ans, k + i);
            }
        }
    } else {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; i++) {
            for (int j = 0; j <= length / arr[1]; j++) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }

    printf("%d\n", ans);
}

int main() {
    cutRibbon();
    return 0;
}
// End of Code
