#include <stdio.h>
#include <stdbool.h>

int main() {
    int c = 0;
    int b = 0;
    int a[100000];
    int x = 0;
    char mark;
    bool finished = false;

    while (!finished) {
        scanf("%d", &c);
        getchar(); // To handle newline character after reading integer
        scanf("%c", &mark);
        scanf("%d", &b);

        if (mark == '?') {
            a[x] = 2000001;
            finished = true;
        } else if (mark == '+') {
            a[x] = c + b;
        } else if (mark == '-') {
            a[x] = c - b;
        } else if (mark == '*') {
            a[x] = c * b;
        } else if (mark == '/') {
            a[x] = c / b;
        }
        x++;
    }

    x = 0;
    while (true) {
        if (a[x] == 2000001) break;
        printf("%d\n", a[x]);
        x++;
    }

    return 0;
}
// 
