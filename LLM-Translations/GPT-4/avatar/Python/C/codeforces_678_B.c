
#include <stdio.h>
#include <stdbool.h>

bool leapyear(int n) {
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    char d = 'f';
    scanf("%d", &n);

    bool ans;
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        ans = true;
    } else {
        ans = false;
    }

    while (1) {
        if (leapyear(n)) {
            if (d == 'm') {
                d = 't';
                n++;
            } else if (d == 't') {
                d = 'w';
                n++;
            } else if (d == 'w') {
                d = 'h';
                n++;
            } else if (d == 'h') {
                d = 'f';
                n++;
            } else if (d == 'f') {
                d = 's';
                n++;
            } else if (d == 's') {
                d = 'm';
                n++;
            }
        } else {
            if (d == 'm') {
                d = 't';
                n++;
            } else if (d == 't') {
                d = 'w';
                n++;
            } else if (d == 'w') {
                d = 'h';
                n++;
            } else if (d == 'h') {
                d = 'f';
                n++;
            } else if (d == 'f') {
                d = 's';
                n++;
            } else if (d == 's') {
                d = 'm';
                n++;
            }
        }

        if (d == 'f' && ans == true && leapyear(n)) {
            break;
        } else if (d == 'f' && ans == false && !leapyear(n)) {
            break;
        }
    }

    printf("%d", n);

    return 0;
}
// End of Code
