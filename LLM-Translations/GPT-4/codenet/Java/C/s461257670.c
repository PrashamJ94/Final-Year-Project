#include <stdio.h>

int Answer(int y, int m, int d);

int main() {
    int count, y, m, d;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%d %d %d", &y, &m, &d);
        printf("%d\n", Answer(y, m, d));
    }

    return 0;
}

int Answer(int y, int m, int d) {
    int result = 1;

    if (y % 3 == 0) {
        result += 20 - d;
    } else if (m % 2 == 0) {
        result += 19 - d;
    } else {
        result += 20 - d;
    }

    for (m += 1; m <= 10; m++) {
        if (y % 3 == 0) {
            result += 20;
        } else {
            if (m % 2 == 0) {
                result += 19;
            } else {
                result += 20;
            }
        }
    }

    for (y += 1; y < 1000; y++) {
        if (y % 3 == 0) {
            result += 200;
        } else {
            result += 195;
        }
    }
    return result;
}
// 
