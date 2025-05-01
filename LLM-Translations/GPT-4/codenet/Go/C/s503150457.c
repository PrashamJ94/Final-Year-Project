#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[100], s2[100], s3[100];
    scanf("%s %s %s", s1, s2, s3);

    char result[4];
    result[0] = toupper(s1[0]);
    result[1] = toupper(s2[0]);
    result[2] = toupper(s3[0]);
    result[3] = '\0';

    printf("%s\n", result);
    return 0;
}

// 
