import java.util.Scanner;
import java.util.stream.Stream;

public class s615507008 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] T = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = sc.nextLong();
        }
        int M = sc.nextInt();
        long[] P = new long[M];
        long[] X = new long[M];
        for (int i = 0; i < M; i++) {
            P[i] = sc.nextLong();
            X[i] = sc.nextLong();
        }
        solve(N, T, M, P, X);
        sc.close();
    }

    public static void solve(int N, long[] T, int M, long[] P, long[] X) {
        for (int i = 0; i < M; i++) {
            long ans = 0;
            for (int j = 0; j < N; j++) {
                if (j == P[i] - 1) {
                    ans += X[i];
                } else {
                    ans += T[j];
                }
            }
            System.out.println(ans);
        }
    }
}

// 
