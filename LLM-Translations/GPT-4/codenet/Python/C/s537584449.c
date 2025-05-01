#include <stdio.h>

int func(int a) {
    int digits[10];
    int temp = a;
    int i = 0;
    int result = 0;

    while (temp != 0) {
        digits[i++] = temp % 10;
        temp = temp / 10;
    }

    for (int j = 0; j < i; j++) {
        result += digits[j];
    }

    if (result == 1) {
        printf("10\n");
    } else {
        printf("%d\n", result);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    func(a);
    return 0;
}
// 
