
import java.util.Scanner;

class Edge {
    int to, pre, c;
}

public class s003531724 {
    static final int N = 100010;
    static Edge[] e = new Edge[N * 2];
    static int[] u = new int[N];
    static int l = 0;

    static void ins(int a, int b, int c) {
        e[++l] = new Edge();
        e[l].to = b;
        e[l].pre = u[a];
        e[l].c = c;
        u[a] = l;
    }

    static int n, m;
    static boolean[] vis = new boolean[N];
    static boolean ok;
    static long[] cnt = new long[3];
    static int[] d = new int[N];
    static int T;

    static void dfs(int x, int l) {
        vis[x] = true;
        cnt[l]++;
        d[x] = l;
        for (int i = u[x]; i != 0; i = e[i].pre) {
            T++;
            int v = e[i].to;
            int ec = e[i].c;
            if (!vis[v]) dfs(v, (l + ec) % 3);
            else if ((l + ec) % 3 != d[v]) ok = false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            ins(a, b, 1);
            ins(b, a, 2);
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                T = 0;
                for (int j = 0; j <= 2; j++) cnt[j] = 0;
                ok = true;
                dfs(i, 0);
                long s = cnt[0] + cnt[1] + cnt[2];
                if (!ok) ans += s * s;
                else {
                    if (cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0)
                        ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
                    else
                        ans += T / 2;
                }
            }
        }
        System.out.println(ans);
    }
}

// 
