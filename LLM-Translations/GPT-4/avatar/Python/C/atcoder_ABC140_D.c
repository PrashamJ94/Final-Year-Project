#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
    int N, K, seg_cnt = 0, cur_happy = 0;
    char S[100001];

    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%s", S);

    for(int i = 0; i < N - 1; i++) {
        if(S[i] != S[i + 1]) {
            seg_cnt += 1;
        }
    }

    cur_happy = N - 1 - seg_cnt;
    int ans;
    if(2 * K >= seg_cnt) {
        ans = N - 1;
    } else {
        ans = cur_happy + 2 * K;
    }
    
    printf("%d\n", ans);

    return 0;
}
// End of Code


