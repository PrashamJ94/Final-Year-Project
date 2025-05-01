
#include <stdio.h>
#include <string.h>

void solve() {
    char S_d[60], T[60], ans[60];
    scanf("%s", S_d);
    scanf("%s", T);

    int end = strlen(S_d) - 1;
    int first = end - strlen(T) + 1;
    while (first >= 0) {
        int t_i = 0;
        for (int s_i = first; s_i <= end; s_i++) {
            if (T[t_i] != S_d[s_i] && S_d[s_i] != '?') {
                break;
            }
            t_i++;
        }
        if (t_i == strlen(T)) {
            break;
        }
        first--;
        end--;
    }

    if (first < 0) {
        printf("UNRESTORABLE\n");
        return;
    }
    
    strcpy(ans, S_d);
    int t_i = 0;
    for (int i = first; i <= end; i++) {
        ans[i] = T[t_i];
        t_i++;
    }
    
    for (int i = 0; i < strlen(ans); i++) {
        if (ans[i] == '?') {
            ans[i] = 'a';
        }
    }
    printf("%s\n", ans);
}

int main() {
    solve();
    return 0;
}
