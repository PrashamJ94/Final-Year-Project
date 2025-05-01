#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b, result;
    scanf("%d %d %d", &n, &a, &b);
    
    result = (n * a < b) ? (n * a) : b;
    printf("%d\n", result);
    
    return 0;
}
// 


