import java.util.*;

public class atcoder_ABC148_F {
    static int n, ta, ao, mod = 1000000007;
    static List<Integer>[] g;
    static int[] ta_dist, ao_dist;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        ta = scanner.nextInt() - 1;
        ao = scanner.nextInt() - 1;
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        ta_dist = new int[n];
        Arrays.fill(ta_dist, -1);
        ta_dist[ta] = 0;
        ao_dist = new int[n];
        Arrays.fill(ao_dist, -1);
        ao_dist[ao] = 0;
        ta_dfs(ta);
        ao_dfs(ao);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ta_dist[i] > ao_dist[i]) continue;
            res = Math.max(res, ao_dist[i]);
        }
        System.out.println(res - 1);
    }

    public static void ta_dfs(int node) {
        for (int v : g[node]) {
            if (ta_dist[v] != -1) continue;
            ta_dist[v] = ta_dist[node] + 1;
            ta_dfs(v);
        }
    }

    public static void ao_dfs(int node) {
        for (int v : g[node]) {
            if (ao_dist[v] != -1) continue;
            ao_dist[v] = ao_dist[node] + 1;
            ao_dfs(v);
        }
    }
}
// End of Code.
