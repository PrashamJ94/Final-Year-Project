#include <stdio.h>
#include <stdbool.h>

int twos_in_factorial(int n) {
    return n - __builtin_popcount(n);
}

bool parity_of_nCr(int n, int i) {
    int f(int x) {
        return twos_in_factorial(x);
    }
    return f(n) - f(n - i) - f(i) > 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        nums[i]--;
    }
    
    bool no_one = true;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            no_one = false;
            break;
        }
    }
    
    if (no_one) {
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
    }
    
    bool is_odd = false;
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1;
        }
    }
    
    if (!is_odd) {
        printf("0\n");
    } else {
        printf("%d\n", 1 << !no_one);
    }

    return 0;
}

// End of Code
