#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char S[100], T[100];
    char A[] = "abcdefghijklmnopqrstuvwxyz";
    scanf("%s %s", S, T);

    bool res = true;
    for (int i = 0; i < 26; i++) {
        char s = A[i];
        int sIdx = -1;
        for (int j = 0; j < strlen(S); j++) {
            if (S[j] == s) {
                sIdx = j;
                break;
            }
        }
        if (sIdx < 0) continue;
        char t = T[sIdx];
        int idx = 0;
        while (idx < strlen(S)) {
            int s_index = -1;
            int t_index = -1;
            for (int k = idx; k < strlen(S); k++) {
                if (S[k] == s) {
                    s_index = k;
                    break;
                }
            }
            for (int k = idx; k < strlen(T); k++) {
                if (T[k] == t) {
                    t_index = k;
                    break;
                }
            }
            if (s_index >= 0) {
                if (s_index != t_index) {
                    res = false;
                    break;
                } else {
                    idx = s_index + 1;
                }
            } else if (t_index >= 0) {
                res = false;
                break;
            } else break;
        }
        if (!res) break;
    }
    if (res) printf("Yes\n");
    else printf("No\n");

    return 0;
}
// //End of Code
