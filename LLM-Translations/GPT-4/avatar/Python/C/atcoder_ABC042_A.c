#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int count_5 = 0;
    if (a == 5) count_5++;
    if (b == 5) count_5++;
    if (c == 5) count_5++;

    if (count_5 == 2) {
        if (a + b + c == 17) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}

// End of Code
