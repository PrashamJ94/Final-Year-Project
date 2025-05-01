#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);

    rep(i,n) {
        char s[1000];
        scanf("%s", s);

        int s_size = strlen(s);
        char temp[1000], temp2[1000], res[1000], res2[1000];

        int st_size = 0;
        char st[1000][1000];
        strcpy(st[st_size++], s);

        REP(j,1,s_size){ 
            strncpy(temp, s, j);
            temp[j] = '\0';

            strncpy(temp2, s+j, s_size-j);
            temp2[s_size-j] = '\0';

            strcpy(res, temp);
            strcpy(res2, temp2);

            strrev(res);
            strrev(res2);

            char combinations[8][1000];
            strcpy(combinations[0], strcat(temp, temp2));
            strcpy(combinations[1], strcat(temp2, temp));
            strcpy(combinations[2], strcat(temp, res2));
            strcpy(combinations[3], strcat(res2, temp));
            strcpy(combinations[4], strcat(res, temp2));
            strcpy(combinations[5], strcat(temp2, res));
            strcpy(combinations[6], strcat(res, res2));
            strcpy(combinations[7], strcat(res2, res));

            for (int k = 0; k < 8; k++) {
                int exists = 0;
                for (int m = 0; m < st_size; m++) {
                    if (strcmp(st[m], combinations[k]) == 0) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    strcpy(st[st_size++], combinations[k]);
                }
            }
        }

        printf("%d\n", st_size);
    }

    return 0;
}
// 
