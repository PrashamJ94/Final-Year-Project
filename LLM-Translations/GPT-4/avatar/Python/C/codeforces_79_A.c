
#include <stdio.h>

int main() {
    int x, y, a = 0;
    scanf("%d %d", &x, &y);
    while(x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2) {
        if (a) {
            if (y >= 22) {
                y -= 22;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else {
                x -= 2;
                y -= 2;
            }
        } else {
            if (x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else {
                y -= 22;
            }
        }
        a = 1 - a;
    }
    printf("%s\n", a == 1 ? "Hanako" : "Ciel");
    return 0;
}
// End of Code

//This C code does the same thing as the Python code. It inputs two numbers, performs a series of operations on them, and then prints either "Ciel" or "Hanako" based on the final state of a variable.
