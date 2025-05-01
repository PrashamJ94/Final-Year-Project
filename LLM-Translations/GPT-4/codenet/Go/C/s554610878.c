#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main() {
    const char *week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    char s[4];
    scanf("%s", s);
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i;
            break;
        }
    }

    printf("%d\n", 7 - index);
    return 0;
}

// 
