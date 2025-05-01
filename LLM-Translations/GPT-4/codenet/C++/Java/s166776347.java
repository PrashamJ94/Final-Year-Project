import java.util.Scanner;

public class s166776347 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long mod = 1000000007;

        // Input
        long N = sc.nextLong();
        long K = sc.nextLong();
        long[] A = new long[(int) N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }

        // Solution
        long ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue;
                if (A[i] > A[j]) ans1++;
                ans1 %= mod;
            }
        }

        long[] count = new long[2005];
        for (int i = 0; i < N; i++) {
            count[(int) (A[i] - 1)]++;
        }
        long ans2 = 0;
        long remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i];
            ans2 += count[i] * remain;
        }

        long ans = 0;
        long tmp = K * (K - 1);
        tmp /= 2;
        tmp %= mod;
        tmp *= ans2;
        tmp %= mod;
        ans += ans1 * K;
        ans %= mod;
        ans += tmp;
        ans %= mod;

        // Output
        System.out.println(ans);
    }
}
// 
