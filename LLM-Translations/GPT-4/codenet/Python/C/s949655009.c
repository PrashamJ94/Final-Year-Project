#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char strn[10];
    snprintf(strn, 10, "%d", n);
    char *shichigolist[] = {"3", "5", "7"};
    int len_strn = strlen(strn);

    char shichigo[len_strn][1000][len_strn + 1];
    memset(shichigo, 0, sizeof(shichigo));

    for (int i = 0; i < len_strn; i++) {
        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                strcpy(shichigo[i][j], shichigolist[j]);
            }
        } else {
            int k = 0;
            for (int j = 0; j < 1000 && shichigo[i - 1][j][0] != '\0'; j++) {
                for (int l = 0; l < 3; l++) {
                    snprintf(shichigo[i][k], len_strn + 1, "%s%c", shichigo[i - 1][j], shichigolist[l][0]);
                    k++;
                }
            }
        }
    }

    int target = len_strn - 1;
    int count = 0;
    for (int i = 0; i < len_strn; i++) {
        for (int j = 0; j < 1000 && shichigo[i][j][0] != '\0'; j++) {
            int num = atoi(shichigo[i][j]);
            if (i == target) {
                if (num > n) {
                    continue;
                }
                int cnt3 = 0, cnt5 = 0, cnt7 = 0;
                for (int k = 0; k < strlen(shichigo[i][j]); k++) {
                    if (shichigo[i][j][k] == '3') cnt3++;
                    if (shichigo[i][j][k] == '5') cnt5++;
                    if (shichigo[i][j][k] == '7') cnt7++;
                }
                if (cnt3 > 0 && cnt5 > 0 && cnt7 > 0) {
                    count++;
                }
            } else {
                int cnt3 = 0, cnt5 = 0, cnt7 = 0;
                for (int k = 0; k < strlen(shichigo[i][j]); k++) {
                    if (shichigo[i][j][k] == '3') cnt3++;
                    if (shichigo[i][j][k] == '5') cnt5++;
                    if (shichigo[i][j][k] == '7') cnt7++;
                }
                if (cnt3 > 0 && cnt5 > 0 && cnt7 > 0) {
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
// 
