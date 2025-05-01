#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_match(const char *set, char c) {
    return strchr(set, c) != NULL;
}

int main() {
    const char *ODD = "RUD";
    const char *EVEN = "LUD";

    char N[101];
    scanf("%s", N);

    bool is_good = true;
    for (int i = 0; i < strlen(N); i++) {
        if ((i + 1) % 2 == 0) {
            if (!is_match(EVEN, N[i])) {
                is_good = false;
                break;
            }
        } else {
            if (!is_match(ODD, N[i])) {
                is_good = false;
                break;
            }
        }
    }

    printf("%s\n", is_good ? "Yes" : "No");
    return 0;
}
// 
