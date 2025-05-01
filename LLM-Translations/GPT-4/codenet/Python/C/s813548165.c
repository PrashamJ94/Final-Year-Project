#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char S[100], T[100], char_lists[200];

    scanf("%d", &N);
    scanf("%s %s", S, T);

    int idx = 0;
    for (int i = 0; i < N; i++) {
        char_lists[idx++] = S[i];
        char_lists[idx++] = T[i];
    }
    char_lists[idx] = '\0';

    printf("%s\n", char_lists);

    return 0;
}
// 
