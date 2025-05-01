#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int h[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &h[i]);
    }
    int max = 0;
    for (int l = 0 ; l < n - 1 ; l++) {
        int count = 0;
        while (l < n - 1 && h[l] >= h[l + 1]) {
            l++;
            count++;
        }
        max = (max > count) ? max : count;
    }
    printf("%d\n", max);
    return 0;
}
// 
