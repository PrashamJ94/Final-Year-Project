#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int day;
    scanf("%d", &day);

    int diff = abs(day - 25);
    char eve[4] = " Eve";
    char result[100] = "Christmas";

    for (int i = 0; i < diff; i++) {
        strcat(result, eve);
    }
    printf("%s\n", result);

    return 0;
}
// 


