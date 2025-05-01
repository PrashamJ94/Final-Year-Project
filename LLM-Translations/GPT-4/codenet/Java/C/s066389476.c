#include <stdio.h>
#include <stdbool.h>

void solve(char* a);

int main() {
    char a[4];
    scanf("%s", a);
    solve(a);
    return 0;
}

void solve(char* a) {
    if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
}
// 
