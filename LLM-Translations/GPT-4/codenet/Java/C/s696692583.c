#include <stdio.h>
#include <stdbool.h>

void tr(char* os) {
    printf("%s\n", os);
}

int main() {
    int my1, my2, enemy1;
    while (scanf("%d %d %d", &my1, &my2, &enemy1) != EOF) {
        bool used[11] = {false};
        used[my1] = true;
        used[my2] = true;
        used[enemy1] = true;
        int all = 0;
        int safe = 0;
        for (int i = 1; i <= 10; i++) {
            if (!used[i]) {
                all++;
                if (my1 + my2 + i <= 20) {
                    safe++;
                }
            }
        }
        if (safe * 2 >= all) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

char solve(int a[3][3]) {
    char s[] = {'d', 'o', 'x'};
    for (int side = 1; side <= 2; side++) {
        for (int i = 0; i < 3; i++) {
            if (a[i][0] == side && a[i][1] == side && a[i][2] == side) {
                return s[side];
            }
            if (a[0][i] == side && a[1][i] == side && a[2][i] == side) {
                return s[side];
            }
        }
        if (a[0][0] == side && a[1][1] == side && a[2][2] == side) {
            return s[side];
        }
        if (a[0][2] == side && a[1][1] == side && a[2][0] == side) {
            return s[side];
        }
    }
    return 'd';
}
