#include <stdio.h>
#include <string.h>

int main() {
    char input1[100], input2[100];
    int count = 0;

    fgets(input1, sizeof(input1), stdin);
    fgets(input2, sizeof(input2), stdin);

    for (int i = 0; i < strlen(input1) && i < strlen(input2); i++) {
        if (input1[i] == input2[i]) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
// 
