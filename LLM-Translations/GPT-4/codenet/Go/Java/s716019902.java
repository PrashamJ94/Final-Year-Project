import java.util.Scanner;
import java.math.BigInteger;

public class s716019902 {
    static final int mod = 998244353;
    static final int facNum = 300001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                continue;
            }
            sum += i;
        }
        System.out.println(sum);
    }

    static int pow(int a, int n) {
        int ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (int)(((long)ans * a) % mod);
            }
            a = (int)(((long)a * a) % mod);
            n = n >> 1;
        }
        return ans;
    }

    static int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }
        while (b != 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int combination(int n, int k, int[] fac, int[] ifac) {
        if (n < k || n < 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        int ans = (int)(((long)ifac[k] * ifac[n - k]) % mod);
        return (int)(((long)ans * fac[n]) % mod);
    }

    static int[] factorial() {
        int[] fac = new int[facNum];
        fac[0] = 1;
        int[] ifac = new int[facNum];
        ifac[0] = 1;
        for (int i = 1; i < facNum; i++) {
            fac[i] = (int)(((long)fac[i - 1] * i) % mod);
            ifac[i] = (int)(((long)ifac[i - 1] * pow(i, mod - 2)) % mod);
        }
        return fac;
    }

    static int lowerBound(int[] vs, int v) {
        int n = vs.length / 2;
        int m = vs.length;
        while (m != n) {
            if (vs[n] < v) {
                n = (m - n + 1) / 2 + n;
            } else {
                m = n;
                n = n / 2;
            }
        }
        return n;
    }

    static int[] intSlice(int n, int init) {
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = init;
        }
        return r;
    }
}
// 
