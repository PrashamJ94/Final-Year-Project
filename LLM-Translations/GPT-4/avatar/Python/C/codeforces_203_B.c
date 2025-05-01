#include <stdio.h>

void solve_case() {
    int n, m, i, j, k, x, y;
    int count[100][100], found, ans = -1;
    
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            count[i][j] = 0;
        }
    }
    
    for(k = 0; k < m; k++) {
        scanf("%d %d", &x, &y);
        x -= 1;
        y -= 1;
        found = 0;
        
        for(i = x - 2; i <= x; i++) {
            for(j = y - 2; j <= y; j++) {
                if(i >= 0 && i < n && j >= 0 && j < n) {
                    count[i][j] += 1;
                    if(count[i][j] == 9) {
                        found = 1;
                    }
                }
            }
        }
        
        if(found) {
            ans = k + 1;
            break;
        }
    }
    
    printf("%d\n", ans);
}

int main() {
    solve_case();
    return 0;
} // End of Code
