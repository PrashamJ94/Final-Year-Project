import java.util.*;
import java.io.*;

public class s853386130 {
    static final int mod = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        int[] rs = new int[R];
        st = new StringTokenizer(r.readLine());
        for (int i = 0; i < R; i++) {
            rs[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        int[][] costs = new int[n][n];
        for (int[] row : costs) {
            Arrays.fill(row, INF);
        }
        for (int i = 0; i < n; i++) {
            costs[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(r.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            costs[a][b] = c;
            costs[b][a] = c;
        }

        // Warshall-Floyd algorithm for shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        // Try all permutations of visiting order
        List<List<Integer>> perms = permutations(rs);
        int ans = INF;
        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j - 1);
                int to = perm.get(j);
                tmp += costs[from][to];
            }
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans);
    }

    // Permutations
    static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        helper(arr, arr.length, res);
        return res;
    }

    static void helper(int[] arr, int n, List<List<Integer>> res) {
        if (n == 1) {
            List<Integer> tmp = new ArrayList<>();
            for (int value : arr) {
                tmp.add(value);
            }
            res.add(tmp);
        } else {
            for (int i = 0; i < n; i++) {
                helper(arr, n - 1, res);
                if (n % 2 == 1) {
                    int tmp = arr[i];
                    arr[i] = arr[n - 1];
                    arr[n - 1] = tmp;
                } else {
                    int tmp = arr[0];
                    arr[0] = arr[n - 1];
                    arr[n - 1] = tmp;
                }
            }
        }
    }
}
// 
