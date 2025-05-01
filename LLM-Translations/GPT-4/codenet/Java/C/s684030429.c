#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//actual logic
void solve(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d\n", (int) fmax(0, a - 2 * b));
}

int main() {
    solve();
    return 0;
}

// 
