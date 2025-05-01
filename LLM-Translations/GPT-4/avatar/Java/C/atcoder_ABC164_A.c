#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int Sheep, Wolve;
    scanf("%d %d", &Sheep, &Wolve);

    if (Wolve >= Sheep) {
        printf("unsafe\n");
    } else {
        printf("safe\n");
    }

    return 0;
}
/* //End of Code */
