#include <stdio.h>

int main() {
    int a, b, t;
    double time = 0;
    int count = 0;

    scanf("%d %d %d", &a, &b, &t);

    while (time < t + 0.5) {
        count += b;
        time += a;
        if (time > t + 0.5) {
            count -= b;
            break;
        }
    }

    printf("%d\n", count);
    return 0;
}

// 
