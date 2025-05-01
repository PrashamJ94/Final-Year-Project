
import java.util.Scanner;

public class atcoder_AGC046_B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int A = in.nextInt();
        int B = in.nextInt();
        int C = in.nextInt();
        int D = in.nextInt();
        in.close();

        int m = 998244353;
        int[][] d = new int[C + 1][D + 1];
        d[A][B] = 1;

        for (int i = A; i <= C; i++) {
            for (int j = B; j <= D; j++) {
                d[i][j] += (int)(((long)d[i][j - 1] * i + (long)d[i - 1][j] * j - (long)d[i - 1][j - 1] * (i - 1) * (j - 1)) % m);
            }
        }

        System.out.println(d[C][D]);
    }
}

// End of Code.
