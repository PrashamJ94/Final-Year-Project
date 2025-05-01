
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s823623405 {
    private static final int mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        Map<Integer, Integer> ps = new HashMap<>();

        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();

            Map<Integer, Integer> ns = primeFactorize(as[i]);
            for (int k : ns.keySet()) {
                ps.put(k, Math.max(ps.getOrDefault(k, 0), ns.get(k)));
            }
        }

        int x = 1;
        for (int k : ps.keySet()) {
            for (int i = 1; i <= ps.get(k); i++) {
                x = mul(x, k);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i]));
        }
        System.out.println(ans);
    }

    private static int max(int a, int b) {
        return a > b ? a : b;
    }

    private static Map<Integer, Integer> primeFactorize(int n) {
        Map<Integer, Integer> res = new HashMap<>();
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                res.put(i, res.getOrDefault(i, 0) + 1);
            }
        }
        if (n != 1) {
            res.put(n, res.getOrDefault(n, 0) + 1);
        }
        return res;
    }

    private static int pow(int n, int k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % mod;
        } else {
            int t = pow(n, k / 2);
            return t * t % mod;
        }
    }

    private static int add(int a, int b) {
        return (a + b) % mod;
    }

    private static int sub(int a, int b) {
        return (a + mod - b) % mod;
    }

    private static int mul(int a, int b) {
        return (int) (((long) a % mod) * ((long) b % mod) % mod);
    }

    private static int div(int a, int b) {
        return mul(a, pow(b, mod - 2));
    }
}

// 
