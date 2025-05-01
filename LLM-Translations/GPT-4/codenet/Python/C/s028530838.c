#include <stdio.h>
#include <ctype.h>

int main() {
    char x;
    scanf("%c", &x);
    
    if (islower(x)) {
        printf("a\n");
    } else {
        printf("A\n");
    }

    return 0;
} // 
