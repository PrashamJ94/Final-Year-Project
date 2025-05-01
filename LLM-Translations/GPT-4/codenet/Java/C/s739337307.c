#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int map[100001] = {0};

    int countAc = 0;
    int countWaAll = 0;

    for (int i = 0; i < m; i++) {
        int question;
        char waOrAc[3];
        scanf("%d %s", &question, waOrAc);

        if (map[question] == 0) {
            if (strcmp(waOrAc, "WA") == 0) map[question] = 1;
            else {
                map[question] = -1;
                countAc++;
            }
        } else {
            int countWa = map[question];
            if (countWa < 0);
            else {
                if (strcmp(waOrAc, "WA") == 0) map[question] = countWa + 1;
                else {
                    map[question] = -countWa;
                    countAc++;
                    countWaAll += countWa;
                }
            }
        }
    }

    printf("%d %d\n", countAc, countWaAll);

    return 0;
}
// 
