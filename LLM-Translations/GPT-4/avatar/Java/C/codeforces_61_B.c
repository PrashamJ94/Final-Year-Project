#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void remove_non_alpha(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

bool compare_strings(char *testCase, char *perm1, char *perm2, char *perm3, char *perm4, char *perm5, char *perm6) {
    return (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0);
}

int main() {
    char word1[101], word2[101], word3[101], testCase[303];
    char perm1[303], perm2[303], perm3[303], perm4[303], perm5[303], perm6[303];
    int students;

    fgets(word1, sizeof(word1), stdin);
    fgets(word2, sizeof(word2), stdin);
    fgets(word3, sizeof(word3), stdin);

    remove_non_alpha(word1);
    remove_non_alpha(word2);
    remove_non_alpha(word3);

    strcpy(perm1, word1); strcat(perm1, word2); strcat(perm1, word3);
    strcpy(perm2, word1); strcat(perm2, word3); strcat(perm2, word2);
    strcpy(perm3, word2); strcat(perm3, word1); strcat(perm3, word3);
    strcpy(perm4, word2); strcat(perm4, word3); strcat(perm4, word1);
    strcpy(perm5, word3); strcat(perm5, word2); strcat(perm5, word1);
    strcpy(perm6, word3); strcat(perm6, word1); strcat(perm6, word2);

    scanf("%d", &students);
    getchar();

    for (int i = 0; i < students; i++) {
        fgets(testCase, sizeof(testCase), stdin);
        remove_non_alpha(testCase);

        if (compare_strings(testCase, perm1, perm2, perm3, perm4, perm5, perm6)) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }

    return 0;
}

// //End of Code
