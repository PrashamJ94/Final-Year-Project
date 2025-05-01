
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char s[1000];
    scanf("%s", s);
    int count = 0;
    int counter[1000] = {0};
    int counterIndex = 0;

    if (s[0] == '\0') {
        return 0;
    }

    counter[counterIndex++] = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            count++;
        } else {
            counter[counterIndex++] = count;
            count = 0;
        }
    }

    counter[counterIndex++] = count;
    qsort(counter, counterIndex, sizeof(int), compare);
    printf("%d\n", counter[counterIndex - 1]);

    return 0;
}

// 
