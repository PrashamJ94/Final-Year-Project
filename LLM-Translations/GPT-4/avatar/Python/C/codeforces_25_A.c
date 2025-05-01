#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        list[i] = x % 2;
        sum += list[i];
    }
    if(sum == 1) {
        for(int i = 0; i < n; i++) {
            if(list[i] == 1) {
                printf("%d", i + 1);
                break;
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            if(list[i] == 0) {
                printf("%d", i + 1);
                break;
            }
        }
    }
    return 0;
} // End of Code
