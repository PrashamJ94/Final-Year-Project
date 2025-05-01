import java.util.Scanner;

public class s375567191 {
    static final int MAX = 101;
    static final int WHITE = 0;
    static final int BLACK = 2;
    static final int GRAY = 1;
    static int time, n;
    static int[][] g = new int[MAX][MAX];
    static int[] d = new int[MAX];
    static int[] f = new int[MAX];
    static int[] color = new int[MAX];

    static void visit(int u) {
        int i;

        color[u] = GRAY;
        d[u] = ++time;

        for (i = 0; i < n; i++) {
            if (g[u][i] == 0)
                continue;
            if (color[i] == WHITE)
                visit(i);
        }

        color[u] = BLACK;
        f[u] = ++time;
    }

    static void dfs() {
        int i;
        time = 0;

        for (i = 0; i < n; i++)
            if (color[i] == WHITE)
                visit(i);

        for (i = 0; i < n; i++)
            System.out.printf("%d %d %d%n", i + 1, d[i], f[i]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i, j, x, y, z;

        n = sc.nextInt();

        for (i = 0; i < n; i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            for (j = 0; j < y; j++) {
                z = sc.nextInt();
                g[x - 1][z - 1] = 1;
            }
        }

        dfs();
    }
}
// 
