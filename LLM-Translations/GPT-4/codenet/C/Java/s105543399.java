
import java.util.Scanner;

public class s105543399 {
    public static void main(String[] args) {
        long n, a, m, M, c, i;
        c = 0;
        m = 100000000;
        M = -100000000;
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();

        for (i = 1; i <= n; i++) {
            a = sc.nextLong();
            if (a > M) {
                M = a;
            }
            if (a < m) {
                m = a;
            }
            c = c + a;
        }
        System.out.printf("%d %d %d%n", m, M, c);
    }
}

// 
