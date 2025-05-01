
#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);

    int d, t, l, r, k = 1;
    char c;

    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    char res[1000] = "";
    int i = 1;
    int j = s;

    scanf("%d %d %d", &t, &l, &r);

    while (j != f) {
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k += 1;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            strcat(res, "X");
        } else {
            strcat(res, &c);
            j += d;
        }
        i += 1;
    }

    printf("%s", res);

    return 0;
}
// End of Code

//The Python code provided is a script that reads from the standard input and writes to the standard output. It appears to be part of a competitive programming problem or something similar. The equivalent C code does the same thing: it reads from the standard input and writes to the standard output. It follows the same logic and steps as the Python code, and uses the standard C library functions to accomplish the tasks.
