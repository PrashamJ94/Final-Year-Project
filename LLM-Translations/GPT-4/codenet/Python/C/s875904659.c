
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void bubbleSort(char cards[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (cards[j][1] < cards[j-1][1]) {
                char temp[3];
                strcpy(temp, cards[j]);
                strcpy(cards[j], cards[j-1]);
                strcpy(cards[j-1], temp);
            }
        }
    }
}

void selectionSort(char cards[][3], int n) {
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (cards[j][1] < cards[mini][1]) {
                mini = j;
            }
        }
        if (mini != i) {
            char temp[3];
            strcpy(temp, cards[i]);
            strcpy(cards[i], cards[mini]);
            strcpy(cards[mini], temp);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char cards[36][3];
    char cards2[36][3];

    for (int i = 0; i < n; i++) {
        scanf("%s", cards[i]);
        strcpy(cards2[i], cards[i]);
    }

    bubbleSort(cards, n);
    printf("Stable\n");

    selectionSort(cards2, n);

    bool is_stable = true;
    for (int i = 0; i < n; i++) {
        if (strcmp(cards[i], cards2[i]) != 0) {
            is_stable = false;
            break;
        }
    }

    if (is_stable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    return 0;
}
