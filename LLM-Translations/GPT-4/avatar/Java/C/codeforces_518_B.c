#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001], t[1001];
    scanf("%s %s", s, t);

    int ura = 0, opa = 0;
    int tmap[128] = {0};

    for (int i = 0; i < strlen(t); i++) {
        tmap[t[i]]++;
    }

    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (tmap[s[i]] > 0) {
            tmap[s[i]]--;
            s[i] = 'Я';
            ura++;
        }
    }

    for (int i = 0; i < length; i++) {
        char rch = (char) (islower(s[i]) ? toupper(s[i]) : tolower(s[i]));
        if (tmap[rch] > 0) {
            tmap[rch]--;
            opa++;
        }
    }

    printf("%d %d\n", ura, opa);
    return 0;
}

// //End of Code
