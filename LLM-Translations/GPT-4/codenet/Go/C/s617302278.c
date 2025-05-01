#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Max returns the max integer among input set.
int Max(int count, int *integers) {
    int m = integers[0];
    for (int i = 1; i < count; i++) {
        if (m < integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

// Min returns the min integer among input set.
int Min(int count, int *integers) {
    int m = integers[0];
    for (int i = 1; i < count; i++) {
        if (m > integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

// PowInt is integer version of pow
int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        printf("[argument error]: PowInt does not accept negative integers");
        exit(1);
    }
    return (int) pow((double) a, (double) e);
}

// AbsInt is integer version of fabs
int AbsInt(int a) {
    return abs(a);
}

// DeleteElement returns a *NEW* array, that have the same and minimum length.
int *DeleteElement(int *s, int length, int index) {
    if (index < 0 || length <= index) {
        printf("[index error]");
        exit(1);
    }

    int *newArr = (int *) malloc((length - 1) * sizeof(int));
    memcpy(newArr, s, index * sizeof(int));
    memcpy(newArr + index, s + index + 1, (length - index - 1) * sizeof(int));
    return newArr;
}

int main() {
    int x;
    scanf("%d", &x);
    int i = 1;
    int sum = 0;
    while (true) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    printf("%d\n", i);
    return 0;
}
// 
