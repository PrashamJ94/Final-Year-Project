
#include <stdio.h>
#include <stdlib.h>

void check(int e) {
    if (e) {
        fprintf(stderr, "error: %d\n", e);
        exit(1);
    }
}

int main() {
    char sage[10];
    fgets(sage, sizeof(sage), stdin);

    switch (atoi(sage)) {
        case 1:
            printf("Hello World\n");
            break;
        case 2: {
            int sum = 0;
            for (int i = 0; i < 2; i++) {
                int num;
                int result = scanf("%d", &num);
                check(result);
                sum += num;
            }
            printf("%d\n", sum);
            break;
        }
    }

    return 0;
}

// 
