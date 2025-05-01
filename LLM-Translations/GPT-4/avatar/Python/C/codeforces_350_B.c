#include <stdio.h>
#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);
    int t[MAX], a[MAX], cnt[MAX], ans[MAX], crt[MAX];
    t[0] = 0;
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i <= n; i++) {
        cnt[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    int ans_len = 0;
    for(int i = 1; i <= n; i++) {
        if(t[i] == 1) {
            int crt_len = 1;
            crt[0] = i;
            int x = a[i];
            while(cnt[x] == 1) {
                crt[crt_len++] = x;
                x = a[x];
            }
            if(crt_len > ans_len) {
                ans_len = crt_len;
                for(int j = 0; j < crt_len; j++) {
                    ans[j] = crt[j];
                }
            }
        }
    }
    for(int i = 0; i < ans_len / 2; i++) {
        int temp = ans[i];
        ans[i] = ans[ans_len - i - 1];
        ans[ans_len - i - 1] = temp;
    }
    printf("%d\n", ans_len);
    for(int i = 0; i < ans_len; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
} // End of Code.
