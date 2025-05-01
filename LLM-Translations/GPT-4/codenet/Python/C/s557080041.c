
#include <stdio.h>
#include <string.h>

int main() {
    int N, sum = 0;
    scanf("%d", &N);

    if (N == 0) {
        printf("Yes\n");
    } else {
        char N_str[12];
        sprintf(N_str, "%d", N);

        for (int i = 0; i < strlen(N_str); i++) {
            sum += N_str[i] - '0';
        }

        if (sum % 9 == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}


