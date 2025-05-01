#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256

int areCountSame(int* count1, int* count2) {
    for (int i = 0; i < MAX_CHAR; i++)
        if (count1[i] != count2[i])
            return 0;
    return 1;
}

void computeCharCounts(char* str, int* count) {
    int i;
    for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
}

char* areAnagram(char* str1, char* str2) {
    int count1[MAX_CHAR] = {0};
    int count2[MAX_CHAR] = {0};

    computeCharCounts(str1, count1);
    computeCharCounts(str2, count2);

    if (areCountSame(count1, count2))
        return "Yes";
    else
        return "No";
}

int main() {
    char str1[MAX_CHAR], str2[MAX_CHAR];
    printf("Enter string 1:\n");
    gets(str1);
    printf("Enter string 2:\n");
    gets(str2);

    printf("%s", areAnagram(str1, str2));

    return 0;
}

// End of Code
