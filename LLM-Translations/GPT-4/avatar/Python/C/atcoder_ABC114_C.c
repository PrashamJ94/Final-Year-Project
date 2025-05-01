#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int N;
int count_753_numbers(char *n) {
    if (atoi(n) > N) {
        return 0;
    }

    bool has7 = false, has5 = false, has3 = false;
    for (int i = 0; i < strlen(n); i++) {
        if (n[i] == '7') has7 = true;
        if (n[i] == '5') has5 = true;
        if (n[i] == '3') has3 = true;
    }

    int ans = (has7 && has5 && has3) ? 1 : 0;
    char new_n[20];
    for (char i = '3'; i <= '7'; i += 2) {
        sprintf(new_n, "%s%c", n, i);
        ans += count_753_numbers(new_n);
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    printf("%d\n", count_753_numbers("0"));
    return 0;
}
// End of Code
