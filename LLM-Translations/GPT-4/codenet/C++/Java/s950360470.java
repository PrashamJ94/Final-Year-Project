import java.math.BigInteger;
import java.util.Scanner;

public class s950360470 {
    private static final BigInteger MOD = BigInteger.valueOf(1000000007);

    // a^n
    private static BigInteger pow(BigInteger a, long n) {
        BigInteger res = BigInteger.ONE;
        while (n > 0) {
            if ((n & 1) == 1) res = res.multiply(a);
            a = a.multiply(a);
            n >>= 1;
        }
        return res;
    }

    // a^n % mod
    private static BigInteger modPow(BigInteger a, long n, BigInteger mod) {
        BigInteger res = BigInteger.ONE;
        while (n > 0) {
            if ((n & 1) == 1) res = res.multiply(a).mod(mod);
            a = a.multiply(a).mod(mod);
            n >>= 1;
        }
        return res;
    }

    // a^(-1) % mod (only if : a % p != 0)
    private static BigInteger modInv(BigInteger a, BigInteger mod) {
        return modPow(a, mod.subtract(BigInteger.valueOf(2)).longValue(), mod);
    }

    // nCk % mod
    private static BigInteger modNCk(int n, int k, BigInteger mod) {
        if (n == 0 || k == 0) return BigInteger.ONE;
        BigInteger p = BigInteger.ONE, q = BigInteger.ONE;
        for (int i = n - k + 1; i <= n; i++) {
            p = p.multiply(BigInteger.valueOf(i)).mod(mod);
        }
        for (int i = 2; i <= k; i++) {
            q = q.multiply(BigInteger.valueOf(i)).mod(mod);
        }
        q = modInv(q, mod);
        return p.multiply(q).mod(mod);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(modNCk(k, n, MOD));
    }
}
// 
