
import java.io.*;
import java.util.*;
import java.math.*;

public class s085554271 {
    static final int MOD = 1000000007;
    static final double PI = 3.14159265358979;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long k = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        for (long i = a; i <= b; i++) {
            if (i % k == 0) {
                System.out.println("OK");
                return;
            }
        }
        System.out.println("NG");
    }

    public static boolean isPrime(int num) {
        if (num < 2) return false;
        else if (num == 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = Math.sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static long gcd(long a, long b) {
        return b != 0 ? gcd(b, a % b) : a;
    }

    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    public static int max(int a, int b, int c) {
        int temp = Math.max(a, b);
        return Math.max(temp, c);
    }

    public static int min(int a, int b, int c) {
        int temp = Math.min(a, b);
        return Math.min(temp, c);
    }

    public static boolean integer(double num) {
        return Math.floor(num) == num;
    }

    public static long fact(int num) {
        if (num == 0)
            return 1;
        else
            return num * fact(num - 1);
    }

    public static long fact_mod(long n, long mod) {
        long f = 1;
        for (long i = 2; i <= n; i++) f = f * (i % MOD) % MOD;
        return f;
    }

    public static long mod_pow(long x, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) > 0) res = (res * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
    }

    public static long combination_mod(long n, long r, long mod) {
        if (r > n - r) r = n - r;
        if (r == 0) return 1;
        long a = 1;
        for (long i = 0; i < r; i++) a = a * ((n - i) % mod) % mod;
        long b = mod_pow(fact_mod(r, mod), mod - 2, mod);
        return (a % mod) * (b % mod) % mod;
    }

    public static boolean rev(String s) {
        String t = new StringBuilder(s).reverse().toString();
        return s.equals(t);
    }
}


