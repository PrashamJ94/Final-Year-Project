import java.util.*;
import java.math.BigInteger;

public class atcoder_ABC152_E {
    static final BigInteger MOD = new BigInteger("1000000007");
    static Scanner scanner = new Scanner(System.in);

    static BigInteger gcd(BigInteger a, BigInteger b) {
        if (b.equals(BigInteger.ZERO)) {
            return a;
        } else {
            return gcd(b, a.mod(b));
        }
    }

    static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(gcd(a, b));
    }

    public static void main(String[] args) {
        int N = scanner.nextInt();
        BigInteger[] A = new BigInteger[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextBigInteger();
        }
        BigInteger _lcm = BigInteger.ONE;
        for (BigInteger a : A) {
            _lcm = _lcm.multiply(a).divide(gcd(_lcm, a));
        }
        BigInteger ans = BigInteger.ZERO;
        for (BigInteger s : A) {
            ans = ans.add(_lcm.multiply(s.modPow(MOD.subtract(BigInteger.valueOf(2)), MOD)));
        }
        ans = ans.mod(MOD);
        System.out.println(ans);
    }
}

// End of Code
