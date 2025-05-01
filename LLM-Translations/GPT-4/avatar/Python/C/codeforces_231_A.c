#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < 2; j++) {
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }
        if(sum > 1) {
            c++;
        }
    }
    printf("%d", c);
    return 0;
}
// End of Code
