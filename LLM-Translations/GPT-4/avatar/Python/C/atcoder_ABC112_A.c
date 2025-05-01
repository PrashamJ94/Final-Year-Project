#include <stdio.h>

int main() {
    int age, a, b;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age == 1) {
        printf("Hello World\n");
    } else {
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}
// End of Code
