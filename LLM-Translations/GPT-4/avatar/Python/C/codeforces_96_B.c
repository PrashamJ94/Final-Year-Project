#include <stdio.h>
#include <stdlib.h>

long long int l[100000];
int size = 0;
long long int limit = 10000000000;

void gen(long long int number, int four, int seven) {
    if (number > limit) {
        return;
    }
    if (number > 0 && four == seven) {
        l[size++] = number;
    }
    gen(number * 10 + 4, four + 1, seven);
    gen(number * 10 + 7, four, seven + 1);
}

int compare(const void *a, const void *b) {
    return (*(long long int *)a - *(long long int *)b);
}

int main() {
    gen(0, 0, 0);
    qsort(l, size, sizeof(long long int), compare);
    long long int n;
    scanf("%lld", &n);
    long long int ans = 0;
    for (int i = 0; i < size; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

// End of Code
