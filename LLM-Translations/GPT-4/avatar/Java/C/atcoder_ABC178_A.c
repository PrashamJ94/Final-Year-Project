#include <stdio.h>
#include <stdbool.h>

int main() {
    int x;
    scanf("%d", &x);
    bool is_one = x == 1 ? true : false;
    int result = !is_one ? 1 : 0;
    printf("%d\n", result);
    return 0;
}

// //End of Code
