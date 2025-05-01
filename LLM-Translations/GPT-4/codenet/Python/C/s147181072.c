#include<stdio.h>
#include<ctype.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);

    for (int i=0; input[i]!='\0'; i++) {
        if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        } else if (islower(input[i])) {
            input[i] = toupper(input[i]);
        }
    }
    printf("%s", input);
    return 0;
}
// 
