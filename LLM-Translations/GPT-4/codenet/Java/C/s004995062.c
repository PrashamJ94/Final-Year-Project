#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char sa[50], sb[50];
    scanf("%s", sa);
    scanf("%s", sb);
    double A = atof(sa);
    double B = atof(sb);
    long long result = (long long)(A * B);
    printf("%lld\n", result);
    return 0;
}

// 
