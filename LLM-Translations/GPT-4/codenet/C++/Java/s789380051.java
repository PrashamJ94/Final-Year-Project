
import java.math.BigInteger;
import java.util.Scanner;

public class s789380051 {

    private static final BigInteger MOD = BigInteger.valueOf(1000000007);

    public static BigInteger mod_pow(BigInteger x, BigInteger n) {
        BigInteger ans = BigInteger.ONE;
        while (n.compareTo(BigInteger.ZERO) > 0) {
            if (n.and(BigInteger.ONE).equals(BigInteger.ONE)) {
                ans = ans.multiply(x).mod(MOD);
            }
            x = x.multiply(x).mod(MOD);
            n = n.shiftRight(1);
        }
        return ans;
    }

    public static BigInteger comb_s(BigInteger n, BigInteger r) {
        BigInteger tmp_n = BigInteger.ONE;
        BigInteger tmp_d = BigInteger.ONE;
        BigInteger ans;
        for (int i = 1; i <= r.intValue(); i++) {
            tmp_n = (tmp_n.multiply(n.add(BigInteger.ONE).subtract(BigInteger.valueOf(i)))).mod(MOD);
            tmp_d = (tmp_d.multiply(BigInteger.valueOf(i))).mod(MOD);
            ans = tmp_n.multiply(mod_pow(tmp_d, MOD.subtract(BigInteger.valueOf(2))));
        }

        return ans;
    }

    public static void main(String[] args) {
        BigInteger n;
        BigInteger a;
        BigInteger b;
        BigInteger ans = BigInteger.ONE;

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextBigInteger();
        a = scanner.nextBigInteger();
        b = scanner.nextBigInteger();
        scanner.close();

        ans = mod_pow(BigInteger.valueOf(2), n);
        ans = ans.subtract(BigInteger.ONE);
        BigInteger tmp_nd;
        tmp_nd = comb_s(n, a);
        ans = (ans.subtract(tmp_nd)).mod(MOD);
        while (ans.compareTo(BigInteger.ZERO) < 0) {
            ans = ans.add(MOD);
        }

        tmp_nd = comb_s(n, b);
        ans = (ans.subtract(tmp_nd)).mod(MOD);
        while (ans.compareTo(BigInteger.ZERO) < 0) {
            ans = ans.add(MOD);
        }

        System.out.println(ans);
    }
}

// 
