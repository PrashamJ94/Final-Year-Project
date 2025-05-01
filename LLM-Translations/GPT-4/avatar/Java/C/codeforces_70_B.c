
#include <stdio.h>
#include <string.h>

int main() {
    int n, max = -1, count = 0, idx = 0;
    char input[500], c;
    
    scanf("%d", &n);
    scanf("%s", input);
    
    int msgLength[strlen(input) / 2];
    
    for (int i = 0; i < strlen(input); i++) {
        c = input[i];
        
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count;
            
            if (count > max) max = count;
            
            i++;
            count = 0;
        } else count++;
    }
    
    if (max > n) printf("Impossible\n");
    else {
        int ans = 0;
        
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i];
            
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1;
                i++;
            }
            
            ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
} // //End of Code


