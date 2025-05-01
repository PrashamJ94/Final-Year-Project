import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class s620821061 {
    static final int V = 520;
    ArrayList<Integer>[] G;
    int[] match;
    boolean[] used;

    public BitMatching() {
        G = new ArrayList[2 * V];
        for (int i = 0; i < 2 * V; i++) {
            G[i] = new ArrayList<>();
        }
        match = new int[2 * V];
        used = new boolean[2 * V];
    }

    void init() {
        for (int i = 0; i < 2 * V; i++) {
            G[i].clear();
        }
    }

    void add(int a, int b) {
        G[a].add(b + V);
        G[b + V].add(a);
    }

    boolean dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v].get(i), w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int exec() {
        int res = 0;
        Arrays.fill(match, -1);
        for (int v = 0; v < V; v++) {
            if (match[v] < 0) {
                Arrays.fill(used, false);
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BitMatching bm = new BitMatching();

        while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            if (n == 0 && m == 0) break;
            bm.init();
            int[] a = new int[n];
            int[] b = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j]) != 1) {
                        bm.add(i, j);
                    }
                }
            }
            System.out.println(bm.exec());
        }
    }
}
// 
