
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int main() {
    int k, x;
    k = getNextInt();
    x = getNextInt();

    char ans[4] = "No";
    if (k * 500 >= x) {
        strcpy(ans, "Yes");
    }
    printf("%s\n", ans);

    return 0;
}


