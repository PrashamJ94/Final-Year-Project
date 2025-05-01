import java.util.Scanner;

public class atcoder_ABC129_E {
    public static void main(String[] args) {
        final long mod = 1000000007;
        Scanner sc = new Scanner(System.in);
        String l = sc.next();
        int n = l.length();
        long[][] dp = new long[n + 1][2];
        dp[0][0] = 1;
        
        for (int i = 0; i < n; i++) {
            char c = l.charAt(i);
            if (c == '0') {
                dp[i + 1][0] += dp[i][0];
                dp[i + 1][1] += dp[i][1] * 3;
            } else {
                dp[i + 1][0] += dp[i][0] * 2;
                dp[i + 1][1] += dp[i][0];
                dp[i + 1][1] += dp[i][1] * 3;
            }
            dp[i + 1][0] %= mod;
            dp[i + 1][1] %= mod;
        }
        
        System.out.println((dp[n][0] + dp[n][1]) % mod);
    }
}
// End of Code
