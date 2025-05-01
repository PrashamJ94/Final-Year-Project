#include <stdio.h>
#define ll long long
#define mod 1000000007

int main(){
    char S[100005];
    int n;
    scanf("%s", S);
    n = strlen(S);

    ll dp[n][13];
    memset(dp, 0, sizeof(dp));
    
    if(n == 1){
        if(S[0] == '5' || S[0] == '?'){
            printf("1\n");
            return 0;
        } else {
            printf("0\n");
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(i == 0){
            if(S[i] != '?'){
                dp[i][(int)(S[i] - '0')] += 1;
            } else {
                for(int j = 0; j < 10; j++){
                    dp[i][j] += 1;
                }
            }
        } else {
            if(S[i] != '?'){
                for(int k = 0; k < 13; k++){
                    dp[i][(k * 10 + (int)(S[i] - '0')) % 13] += dp[i - 1][k];
                }
            } else {
                for(int j = 0; j < 10; j++){
                    for(int k = 0; k < 13; k++){
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
            for(int k = 0; k < 13; k++){
                dp[i][k] %= mod;
            }
        }
    }
    printf("%lld\n", dp[n - 1][5]);
    return 0;
} 
// End of Code
