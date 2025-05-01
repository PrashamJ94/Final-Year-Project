#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void run(char *Sd, char *T) {
    int count = 0;
    char c;
    bool ok = false;
    int first = -1;
    int end = -1;
    int Sd_length = strlen(Sd);
    int T_length = strlen(T);

    for (int j = 0; j < Sd_length; j++) {
        count = 0;
        for (int i = 0; i + j < Sd_length; i++) {
            c = Sd[i + j];
            if (c == '?' || c == T[count]) {
                count++;
                if (count == T_length) {
                    first = i + j - T_length + 1;
                    end = i + j;
                    ok = true;
                    break;
                }
            } else count = 0;
        }
    }
    if (ok) {
        for (int i = 0; i < Sd_length; i++) {
            if (first <= i && i <= end) {
                printf("%c", T[i - first]);
            } else {
                if (Sd[i] == '?') printf("a");
                else printf("%c", Sd[i]);
            }
        }
        printf("\n");
    } else {
        printf("UNRESTORABLE\n");
    }
}

int main() {
    char Sd[100];
    char T[100];
    scanf("%s", Sd);
    scanf("%s", T);
    run(Sd, T);
    return 0;
}

//
