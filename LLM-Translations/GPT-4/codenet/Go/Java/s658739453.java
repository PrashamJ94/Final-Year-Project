import java.util.HashMap;
import java.util.Scanner;

public class s658739453 {

    public static void main(String[] args) {
        final int d = 1000000007;

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();

        HashMap<Long, Long> mdans = new HashMap<>();
        for (int index = 0; index < p; index++) {
            long n1 = sc.nextLong();
            mdans.put(n1, n1);
        }
        sc.close();

        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        if (mdans.containsKey(1L)) {
            dp[1] = 0;
        }

        for (int i = 2; i <= n; i++) {
            if (mdans.containsKey((long) i)) {
                continue;
            }
            dp[i] = (dp[i - 1] + dp[i - 2]) % d;
        }

        System.out.println(dp[n]);
    }
}
// 
