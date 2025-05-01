import java.math.BigInteger;
import java.util.Scanner;

public class s840967243 {
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }

        BigInteger factN = factorial(n);
        BigInteger factM = factorial(m);
        BigInteger result = BigInteger.valueOf(Math.max(2 - m + n, 0)).multiply(factN).multiply(factM).mod(BigInteger.valueOf(MOD));
        System.out.println(result);

    }

    public static BigInteger factorial(int n) {
        BigInteger result = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
}
// 
