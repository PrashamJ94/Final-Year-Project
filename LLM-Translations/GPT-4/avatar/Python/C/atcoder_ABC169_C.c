#include <stdio.h>
#include <math.h>

int main() {
    char sa[10], sb[10];
    int a, b;
    long long result;

    scanf("%s %s", sa, &sb);
    a = atoi(sa);
    b = (int)(atof(sb) * 100 + 0.1);

    result = (long long)(a * b) / 100;
    printf("%lld\n", result);

    return 0;
}
// End of Code
