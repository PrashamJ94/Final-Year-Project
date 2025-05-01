#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    int r[n];
    for (int i = 0; i < n; i++){
        scanf("%d %d", &l[i], &r[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += r[i] - l[i] + 1;
    }
    printf("%d\n", sum);
    return 0;
}
// 
