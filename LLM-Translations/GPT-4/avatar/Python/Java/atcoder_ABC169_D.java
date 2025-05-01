import java.util.*;
import java.math.*;

public class atcoder_ABC169_D {
    public static final BigInteger INF = new BigInteger("999999999999999999999999");
    public static final int MOD = (int) (1e9 + 7);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n == 1) {
            System.out.println(0);
            System.exit(0);
        }

        Map<Integer, Integer> fac = primeFactorize(n);
        int ans = 0;

        for (Map.Entry<Integer, Integer> entry : fac.entrySet()) {
            int x = entry.getValue();
            for (int i = 1; i < 99999999; i++) {
                if (x >= i) {
                    x -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }
        System.out.println(ans);
    }

    public static Map<Integer, Integer> primeFactorize(int n) {
        Map<Integer, Integer> factors = new HashMap<>();
        while (n % 2 == 0) {
            factors.put(2, factors.getOrDefault(2, 0) + 1);
            n /= 2;
        }
        int f = 3;
        while (f * f <= n) {
            if (n % f == 0) {
                factors.put(f, factors.getOrDefault(f, 0) + 1);
                n /= f;
            } else {
                f += 2;
            }
        }
        if (n != 1) {
            factors.put(n, factors.getOrDefault(n, 0) + 1);
        }
        return factors;
    }
}
// End of Code.
