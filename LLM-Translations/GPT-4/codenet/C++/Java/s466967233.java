
import java.util.Arrays;
import java.util.Scanner;

public class s466967233 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[200100];
        long[] B = new long[200100];
        Arrays.fill(B, -1);
        int now = 1;
        long cnt = 0;

        for (int i = 0; i < N; i++) {
            A[i + 1] = scanner.nextLong();
        }

        long j;
        B[1] = 0;
        for (j = 1; j <= K; j++) {
            now = (int) A[now];
            if (B[now] == -1) {
                B[now] = j;
            } else {
                cnt = j;
                break;
            }
        }
        if (j < K) {
            long tmp;
            tmp = (K - B[now]) % (cnt - B[now]);
            for (long i = 0; i < tmp; i++) {
                now = (int) A[now];
            }
        }
        System.out.println(now);
    }
}


