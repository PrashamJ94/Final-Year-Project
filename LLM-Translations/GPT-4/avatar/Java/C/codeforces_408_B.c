#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    bool map[256] = {0};
    for (int i = 0; i < n1; i++) {
        map[(int)s1[i]] = true;
    }
    for (int i = 0; i < n2; i++) {
        if (!map[(int)s2[i]]) return false;
    }
    return true;
}

int main() {
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    if (!isValid(s1, s2)) {
        printf("-1\n");
    }
    else {
        int m1[256] = {0};
        int m2[256] = {0};
        for (int i = 0; i < strlen(s1); i++) {
            m1[(int)s1[i]]++;
        }
        for (int i = 0; i < strlen(s2); i++) {
            m2[(int)s2[i]]++;
        }
        int ans = 0;
        bool hs[256] = {0};
        for (int i = 0; i < strlen(s2); i++) {
            if (!hs[(int)s2[i]]) {
                hs[(int)s2[i]] = true;
                int x1 = m1[(int)s2[i]];
                int x2 = m2[(int)s2[i]];
                x1 = x1 < x2 ? x1 : x2;
                ans += x1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

// //End of Code
