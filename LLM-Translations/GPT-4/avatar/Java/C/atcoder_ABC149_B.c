#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long A, B, K;
    long x, y;
} atcoder_ABC149_B;

void calc(atcoder_ABC149_B* ins) {
    ins->x = ins->A;
    ins->y = ins->B;
    ins->x = ins->A - ins->K;
    if (ins->x < 0) {
        ins->y = ins->B + ins->x;
        ins->x = 0;
        if (ins->y < 0) {
            ins->y = 0;
        }
    }
}

void showResult(atcoder_ABC149_B* ins) {
    printf("%ld %ld\n", ins->x, ins->y);
}

int main() {
    long A, B, K;
    scanf("%ld %ld %ld", &A, &B, &K);

    atcoder_ABC149_B ins;
    ins.A = A;
    ins.B = B;
    ins.K = K;

    calc(&ins);
    showResult(&ins);

    return 0;
}

// //End of Code
