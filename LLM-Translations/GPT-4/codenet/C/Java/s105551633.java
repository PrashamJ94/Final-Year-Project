import java.util.Scanner;

public class s105551633 {
    public static void main(String[] args) {
        run();
    }

    private static long digit(long n) {
        int res = 0;
        while (n > 0) {
            res++;
            n /= 10;
        }
        return res;
    }

    private static long max(long a, long b) {
        return (a > b) ? a : b;
    }

    private static long min(long a, long b) {
        return (a < b) ? a : b;
    }

    private static void run() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long min = digit(n);
        for (int i = 1; (long) i * i <= n; i++) {
            if (n % i != 0) continue;
            long a = i;
            long b = n / i;
            min = min(min, max(digit(a), digit(b)));
        }
        System.out.println(min);
    }
}
// 
