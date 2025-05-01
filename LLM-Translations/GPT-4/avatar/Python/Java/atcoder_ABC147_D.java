import java.util.Scanner;
import java.util.Arrays;

public class atcoder_ABC147_D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        long result = 0;
        long MOD = 1000000007;
        for (int b = 0; b < 60; b++) {
            long bs = 0;
            for (int i = 0; i < N; i++) {
                if ((A[i] & (1L << b)) != 0) {
                    bs++;
                }
            }
            result = (result + bs * (N - bs) * (1L << b)) % MOD;
        }
        System.out.println(result);
    }
}
// End of Code
