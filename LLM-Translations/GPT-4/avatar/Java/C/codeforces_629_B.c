#include <stdio.h>

int main() {
    int n;
    int FfriendPerDay[367] = {0};
    int MfriendPerDay[367] = {0};
    int answer = 0;
    char c;
    int a, b;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        scanf("%d", &a);
        scanf("%d", &b);
        
        for (int j = a; j <= b; j++) {
            if (c == 'M') {
                MfriendPerDay[j]++;
            } else {
                FfriendPerDay[j]++;
            }
            
            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                if (MfriendPerDay[j] > answer) {
                    answer = MfriendPerDay[j];
                }
            } else {
                if (FfriendPerDay[j] > answer) {
                    answer = FfriendPerDay[j];
                }
            }
        }
    }
    
    printf("%d", answer * 2);
    return 0;
}
// //End of Code.
