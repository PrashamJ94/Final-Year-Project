#include <stdio.h>
#include <string.h>

int main() {
    char c;
    scanf("%c", &c);
    
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    char *p = strchr(a, c);
    
    if(p != NULL) {
        int index = p - a;
        printf("%c\n", a[index + 1]);
    }

    return 0;
}
// End of Code
