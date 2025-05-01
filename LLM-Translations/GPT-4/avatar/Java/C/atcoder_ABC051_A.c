#include <stdio.h>
#include <string.h>

int main() {
    char a[101];
    fgets(a, sizeof(a), stdin);

    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ',') {
            a[i] = ' ';
        }
    }
    printf("%s", a);

    return 0;
}
// //End of Code
