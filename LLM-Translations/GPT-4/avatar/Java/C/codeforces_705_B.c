
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    int arr[t];

    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }

    int prevWinner = 0;

    for (int i = 0; i < t; i++) {
        if (arr[i] == 1) {
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }

        if (prevWinner == 2 || prevWinner == 0) {
            if ((arr[i] - 1) % 2 == 0) {
                printf("%d\n", 2);
                prevWinner = 2;
            } else {
                printf("%d\n", 1);
                prevWinner = 1;
            }
        } else {
            if ((arr[i] - 1) % 2 == 0) {
                printf("%d\n", 1);
                prevWinner = 1;
            } else {
                printf("%d\n", 2);
                prevWinner = 2;
            }
        }
    }

    return 0;
}

// //End of Code


