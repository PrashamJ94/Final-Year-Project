//java
import java.util.*;
import java.io.*;

public class s124725275 {
    static int H, W;
    static int[][] S, D;
    static int si, sj, ti, tj;
    static int INF = 2147483648;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        si = sc.nextInt() - 1;
        sj = sc.nextInt() - 1;
        ti = sc.nextInt() - 1;
        tj = sc.nextInt() - 1;
        S = new int[H][W];
        D = new int[H][W];
        for (int i = 0; i < H; i++) {
            String line = sc.next();
            for (int j = 0; j < W; j++) {
                S[i][j] = line.charAt(j) == '#' ? 1 : 0;
                D[i][j] = -1;
            }
        }

        bfs();

        System.out.println(D[ti][tj]);
    }

    static void bfs() {
        Deque<int[]> que = new ArrayDeque<>();
        que.offer(new int[] {0, si, sj});
        int[] dx = {-2, -1, 0, 1, 2};
        int[] dy = {-2, -1, 0, 1, 2};

        while (!que.isEmpty()) {
            int[] current = que.poll();
            int c = current[0], i = current[1], j = current[2];
            if (D[i][j] != -1) {
                continue;
            }
            D[i][j] = c;
            for (int di : dx) {
                for (int dj : dy) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || nj < 0 || ni >= H || nj >= W || D[ni][nj] != -1 || ni == nj && ni == 0 || S[ni][nj] == 1) {
                        continue;
                    }
                    if (di == 0 && Math.abs(dj) == 1 || dj == 0 && Math.abs(di) == 1) {
                        que.offerFirst(new int[] {c, ni, nj});
                    } else {
                        que.offer(new int[] {c + 1, ni, nj});
                    }
                }
            }
        }
    }
}
// 

