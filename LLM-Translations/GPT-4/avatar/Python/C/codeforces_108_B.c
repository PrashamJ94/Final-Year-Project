#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    int int_a = *((int *) a);
    int int_b = *((int *) b);

    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

char *s() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmpfunc);

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    printf("%s\n", s());
    return 0;
}
// End of Code
