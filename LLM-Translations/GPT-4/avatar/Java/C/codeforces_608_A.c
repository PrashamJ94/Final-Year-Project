#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    int max = 0;

    while (n-- > 0) {
        int f, t;
        scanf("%d %d", &f, &t);
        if (max < f + t) {
            max = f + t;
        }
    }

    printf("%d\n", (max > s) ? max : s);
    return 0;
}

// //End of Code
