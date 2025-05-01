#include <stdio.h>
#include <string.h>

int main() {
    char *youbi[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    char s[4];
    int ans = 0;
    
    scanf("%s", s);
    
    for(int i = 0; i < 7; i++) {
        if (strcmp(youbi[i], s) == 0) {
            ans = 7 - i;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
// 
