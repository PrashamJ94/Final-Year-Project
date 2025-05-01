
#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int sub(int a, int b) {
    int min_val = min(a, b);
    int max_val = max(a, b);
    int result = 0;

    while (min_val > 0) {
        result += max_val / min_val;
        max_val = max_val % min_val;
        int curr_min = min(min_val, max_val);
        int curr_max = max(min_val, max_val);
        min_val = curr_min;
        max_val = curr_max;
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", sub(a, b));
    }

    return 0;
}

// //End of Code
