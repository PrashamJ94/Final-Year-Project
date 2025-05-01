
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC150_E {
    private static final int mod = 1000000007;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }
        in.close();

        Arrays.sort(c);
        int b = powMod(2, 2 * n - 2, mod);
        int a = (2 * b) % mod;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long) c[n - 1 - i] * (a + i * b);
            ans %= mod;
        }
        System.out.println(ans);
    }

    private static int powMod(int base, int exponent, int mod) {
        long result = 1;
        long currBase = base;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * currBase) % mod;
            }
            currBase = (currBase * currBase) % mod;
            exponent /= 2;
        }
        return (int) result;
    }
}

// End of Code.
