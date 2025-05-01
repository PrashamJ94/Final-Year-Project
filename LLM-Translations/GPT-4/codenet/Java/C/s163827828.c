#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N, a_num = 0, b_num = 0, ans = 0;
    bool flag = true;
    
    scanf("%d", &N);
    char s[N][1000];
    
    for(int i = 0; i < N; i++) {
        scanf("%s", s[i]);
        
        if(s[i][0] == 'B') {
            b_num++;
        }
        
        if(s[i][strlen(s[i]) - 1] == 'A') {
            a_num++;
        }
        
        if(s[i][0] == 'B' || s[i][strlen(s[i]) - 1] == 'A') {
            if(!(s[i][0] == 'B' && s[i][strlen(s[i]) - 1] == 'A')) {
                flag = false;
            }
        }
        
        for(int j = 0; j < strlen(s[i]) - 1; j++) {
            if(s[i][j] == 'A' && s[i][j + 1] == 'B') {
                ans++;
            }
        }
    }
    
    ans += (a_num < b_num) ? a_num : b_num;
    
    if((a_num < b_num ? a_num : b_num) != 0 && flag) {
        ans--;
    }
    
    printf("%d\n", ans);
    return 0;
}

// 
