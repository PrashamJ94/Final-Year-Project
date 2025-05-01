
import java.util.Scanner;

public class s419237275 {

    static final int N = 200;
    static final int SHIRO = 0;
    static final int HAI = 1;
    static final int KURO = 2;

    static int n;
    static int[][] A = new int[N][N];
    static int[] color = new int[N];
    static int[] d = new int[N];
    static int[] f = new int[N];
    static int TT;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int u, k, v;
        int i, j;

        n = scanner.nextInt();

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++) {
            u = scanner.nextInt() - 1;
            k = scanner.nextInt();
            for (j = 0; j < k; j++) {
                v = scanner.nextInt() - 1;
                A[u][v] = 1;
            }
        }

        aaaaa();

        scanner.close();
    }

    static void aaaaa() {
        int u, i;

        for (i = 0; i < n; i++) {
            color[i] = SHIRO;
        }

        TT = 0;

        for (u = 0; u < n; u++) {
            if (color[u] == SHIRO) {
                bbbbb(u);
            }
        }

        for (i = 0; i < n; i++) {
            System.out.printf("%d %d %d%n", i + 1, d[i], f[i]);
        }
    }

    static void bbbbb(int k) {
        int v;
        color[k] = HAI;
        TT++;
        d[k] = TT;
        for (v = 0; v < n; v++) {
            if (A[k][v] == 0) continue;
            if (color[v] == SHIRO) {
                bbbbb(v);
            }
        }
        color[k] = KURO;
        f[k] = ++TT;
    }
}

// 
