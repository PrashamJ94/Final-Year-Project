#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void main() {
    int N;
    scanf("%d", &N);

    switch (N % 10) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
        printf("hon\n");
        break;
    case 0:
    case 1:
    case 6:
    case 8:
        printf("pon\n");
        break;
    case 3:
        printf("bon\n");
        break;
    }
}

// 
