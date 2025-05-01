
import java.util.Scanner;

public class s497487985 {
    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    public static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        long q = sc.nextLong();

        long[] a = new long[100001];
        long[] point = new long[100001];

        for (long i = 0; i < q; i++) {
            a[(int) i] = sc.nextLong();
            point[(int) (a[(int) i] - 1)]++;
        }

        for (long i = 0; i < n; i++) {
            if (k - (q - point[(int) i]) > 0) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }

        sc.close();
    }
}

// 
