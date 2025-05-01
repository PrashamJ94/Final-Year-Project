import java.util.Scanner;

public class s992338735 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, S;

        while ((N = scanner.nextInt()) > 0) {
            int M, m, addup, i;
            M = -1;
            m = 1001;
            addup = 0;
            for (i = 0; i < N; i++) {
                S = scanner.nextInt();
                addup += S;
                if (S > M) M = S;
                if (S < m) m = S;
            }
            System.out.println((addup - M - m) / (N - 2));
        }
        scanner.close();
    }
}
// 
