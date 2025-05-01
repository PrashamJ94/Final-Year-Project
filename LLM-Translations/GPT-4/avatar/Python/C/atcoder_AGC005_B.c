
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], par[n], rank[n], size[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;
    }
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        int k = b[i];
        int l = 1, r = 1;
        if (k > 0 && a[k - 1] > a[k]) {
            l += size[par[k - 1]];
            par[k] = par[k - 1];
        }
        if (k + 1 < n && a[k + 1] > a[k]) {
            r += size[par[k + 1]];
            par[k] = par[k + 1];
        }
        size[k] = l + r - 1;
        c += l * r * a[k];
    }
    printf("%d\n", c);
    return 0;
}
/* End of Code */

//This C code is a direct translation of your Python code. It uses arrays for 'par', 'rank', 'size', 'a', and 'b'. Please note that the original Python code does not handle the input and output, so you might need to add some additional code to handle it in C.
