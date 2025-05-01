#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int Nums[6];
} Dice;

void rotate(Dice *d, const char *direction, int times) {
    times %= 4;
    int temp;
    while (times--) {
        if (*direction == 'W') {
            temp = d->Nums[0];
            d->Nums[0] = d->Nums[2];
            d->Nums[2] = d->Nums[5];
            d->Nums[5] = d->Nums[3];
            d->Nums[3] = temp;
        } else if (*direction == 'E') {
            temp = d->Nums[0];
            d->Nums[0] = d->Nums[3];
            d->Nums[3] = d->Nums[5];
            d->Nums[5] = d->Nums[2];
            d->Nums[2] = temp;
        } else if (*direction == 'N') {
            temp = d->Nums[0];
            d->Nums[0] = d->Nums[1];
            d->Nums[1] = d->Nums[5];
            d->Nums[5] = d->Nums[4];
            d->Nums[4] = temp;
        } else if (*direction == 'S') {
            temp = d->Nums[0];
            d->Nums[0] = d->Nums[4];
            d->Nums[4] = d->Nums[5];
            d->Nums[5] = d->Nums[1];
            d->Nums[1] = temp;
        }
    }
}

void roll(Dice *d, const char *direction, int times) {
    times %= 4;
    int temp;
    while (times--) {
        if (*direction == 'R') {
            temp = d->Nums[3];
            d->Nums[3] = d->Nums[1];
            d->Nums[1] = d->Nums[2];
            d->Nums[2] = d->Nums[4];
            d->Nums[4] = temp;
        } else if (*direction == 'L') {
            temp = d->Nums[3];
            d->Nums[3] = d->Nums[4];
            d->Nums[4] = d->Nums[2];
            d->Nums[2] = d->Nums[1];
            d->Nums[1] = temp;
        }
    }
}

bool isEqual(Dice d1, Dice d2) {
    for (int i = 0; i < 6; i++) {
        if (d1.Nums[i] != d2.Nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    Dice dice1, dice2;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice1.Nums[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice2.Nums[i]);
    }

    const char *directionOrder[] = {"N", "S", "W", "E"};
    const char *rollOrder[] = {"R", "L"};
    bool flag = false;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 2; l++) {
                    Dice tmp = dice2;
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[l], j);
                    if (isEqual(dice1, tmp)) {
                        flag = true;
                        goto CHECK;
                    }
                }
            }
        }
    }
    CHECK:
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 
