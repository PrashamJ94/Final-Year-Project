
class Pazz {
    static final int N = 4;
    int[][] P = new int[N][N];
}

public class s858559569 {
    static Pazz Q = new Pazz();
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public static int Heu(Pazz Q) {
        int i, j;
        int hx, hy, sum = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (Q.P[i][j] == 0) continue;

                hx = (Q.P[i][j] - 1) % N - j;
                hy = (Q.P[i][j] - 1) / N - i;

                if (hx < 0) sum -= hx;
                else sum += hx;

                if (hy < 0) sum -= hy;
                else sum += hy;
            }
        }
        return sum;
    }

    public static int dfs(int x, int y, int max, int count, int n) {
        int i, temp;
        int x0, y0, ans = -1, h;

        h = Heu(Q);

        if (h == 0) return count;
        if ((count + h) > max) return -1;

        for (i = 0; i < 4; i++) {
            x0 = x + dx[i];
            y0 = y + dy[i];

            if (((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)))
                continue;
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;

            ans = dfs(x0, y0, max, count + 1, i);

            if (ans != -1) return ans;
            temp = Q.P[y][x];
            Q.P[y][x] = Q.P[y0][x0];
            Q.P[y0][x0] = temp;
        }

        return -1;

    }

    public static void main(String[] args) {
        int i, j;
        int kx = 0, ky = 0, ans, a;
        Pazz tP;

        Scanner sc = new Scanner(System.in);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                a = sc.nextInt();
                Q.P[i][j] = a;
                if (a == 0) {
                    kx = j;
                    ky = i;
                }
            }
        }
        sc.close();

        tP = Q;
        for (i = 1; i < 46; i++) {
            Q = tP;
            ans = dfs(kx, ky, i, 0, -1);
            if (ans != -1) {
                System.out.println(ans);
                break;
            }
        }
    }
}

// 
