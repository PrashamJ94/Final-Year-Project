
import java.util.*;
import java.io.*;
import java.math.*;

public class s877835664 {
    static long gcd(long a, long b) { return b != 0 ? gcd(b, a % b) : a; }
    static long lcm(long a, long b) { return a / gcd(a, b) * b; }

    static boolean isPrimeNumber(long num) {
        if (num <= 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = Math.sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        while (b != 0) {
            long t = a / b;
            a -= t * b;
            long tmp = a;
            a = b;
            b = tmp;
            u -= t * v;
            tmp = u;
            u = v;
            v = tmp;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextInt();
        long K = sc.nextInt();

        long[] A = new long[(int)N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }

        long cur = 1;
        long[] dic = new long[(int)N + 1];
        Arrays.fill(dic, -1);
        boolean flg = false;
        for (int i = 1; i <= K; i++) {
            if (dic[(int)cur] < 0 || flg) {
                dic[(int)cur] = i;
                cur = A[(int)cur];
            }
            else if(!flg) {
                long tmp = K - (dic[(int)cur] - 1);
                tmp %= i - dic[(int)cur];
                i = (int)(K - tmp);
                flg = true;
            }
        }

        System.out.println(cur);
    }
}

// 
