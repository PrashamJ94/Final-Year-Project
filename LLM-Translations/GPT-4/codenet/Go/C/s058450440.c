
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans = 0;
int a[5];

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < 5; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char c;
    int dic[128] = {0};

    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[c]++;
        }
    }

    a[0] = dic['M'];
    a[1] = dic['A'];
    a[2] = dic['R'];
    a[3] = dic['C'];
    a[4] = dic['H'];

    dfs(3, 0, 1);
    
    printf("%d\n", ans);
    return 0;
}


