import java.util.*;

public class s951169509 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        sc.nextLine();

        char[][] G = new char[H + 2][W + 2];
        for (int i = 0; i < H + 2; i++) {
            if (i == 0 || i == H + 1) {
                Arrays.fill(G[i], '#');
            } else {
                String line = sc.nextLine();
                G[i] = ('#' + line + '#').toCharArray();
            }
        }

        int ans = 0;
        for (int sx = 0; sx < W + 2; sx++) {
            for (int sy = 0; sy < H + 2; sy++) {
                if (G[sy][sx] == '.') {
                    int[][] dist = new int[H + 2][W + 2];
                    for (int[] row : dist) {
                        Arrays.fill(row, Integer.MIN_VALUE);
                    }
                    int[][] visited = new int[H + 2][W + 2];

                    Queue<int[]> q = new ArrayDeque<>();
                    q.add(new int[]{sx, sy});
                    dist[sy][sx] = 0;
                    visited[sy][sx] = 1;

                    while (!q.isEmpty()) {
                        int[] pos = q.poll();
                        int x = pos[0];
                        int y = pos[1];

                        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                        for (int[] dir : dirs) {
                            int newX = x + dir[0];
                            int newY = y + dir[1];

                            if (G[newY][newX] == '.' && visited[newY][newX] == 0) {
                                q.add(new int[]{newX, newY});
                                dist[newY][newX] = dist[y][x] + 1;
                                visited[newY][newX] = 1;
                            }
                        }
                    }

                    for (int i = 0; i < W + 2; i++) {
                        for (int j = 0; j < H + 2; j++) {
                            ans = Math.max(ans, dist[j][i]);
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
// 
