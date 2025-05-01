
import java.util.Scanner;

public class s343804973 {
    static int N = 310;
    static long mod;
    static long[][] C = new long[N][N], pre = new long[N][N], f = new long[N][N];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        mod = sc.nextLong();
        sc.close();

        C[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
        for (int i = 0; i <= m; i++) {
            f[1][i] = 1;
            pre[1][i] = m - i + 1;
        }
        for (int i = 2; i <= n + 1; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k < i; k++) {
                    f[i][j] = (f[i][j] + f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]) % mod;
                }
            }
            for (int j = m; j >= 0; j--) {
                pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod;
            }
        }
        System.out.println(f[n + 1][0]);
    }
}

// 
