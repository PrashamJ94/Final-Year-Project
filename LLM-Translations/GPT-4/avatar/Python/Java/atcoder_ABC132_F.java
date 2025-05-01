import java.util.Scanner;

public class atcoder_ABC132_F {
    public static void main(String[] args) {
        int mod = 1000000007;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] coef = new int[n];
        int index = 0;

        for (int i = 1; i <= Math.sqrt(n); i++) {
            coef[index++] = (n / i) - (n / (i + 1));
        }

        for (int i = 0; i < n - index; i++) {
            coef[index++] = 1;
        }

        int nn = index;
        int[][] dp = new int[k + 1][nn];

        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            int tmp = 0;
            for (int j = nn - 1; j >= 0; j--) {
                tmp += dp[i - 1][(nn - 1) - j];
                tmp %= mod;
                dp[i][j] = coef[j] * tmp;
                dp[i][j] %= mod;
            }
        }

        int sum = 0;
        for (int i = 0; i < dp[k].length; i++) {
            sum += dp[k][i];
        }
        System.out.println(sum % mod);
    }
}
// End of Code
