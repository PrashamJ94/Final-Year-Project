#include <stdio.h>
#include <stdbool.h>

void solve() {
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    int first, second;
    bool ok = false;

    for (int i = 0; i < t; i++) {
        first = a - (da * i);
        for (int j = 0; j < t; j++) {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = true;
                break;
            }
        }
    }

    if (ok)
        printf("YES");
    else
        printf("NO");
}

int main() {
    solve();
    return 0;
}

// //End of Code
