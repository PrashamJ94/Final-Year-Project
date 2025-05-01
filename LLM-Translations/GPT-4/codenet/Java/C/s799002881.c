#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        if(sqrt(x * x + y * y) <= d) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
// 
