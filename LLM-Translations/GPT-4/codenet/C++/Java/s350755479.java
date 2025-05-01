import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s350755479 {

    static final int maxn = (int) 1e5 + 5;

    static class Node {
        int x, y, id;
    }

    static class Edge implements Comparable<Edge> {
        int u, v, val;

        @Override
        public int compareTo(Edge rhs) {
            return Integer.compare(this.val, rhs.val);
        }
    }

    static int[] par = new int[maxn];
    static int n;

    static Comparator<Node> cmp1 = (a, b) -> Integer.compare(a.x, b.x);

    static Comparator<Node> cmp2 = (a, b) -> Integer.compare(a.y, b.y);

    static void init() {
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    static int findpar(int x) {
        return par[x] = (par[x] == x ? x : findpar(par[x]));
    }

    static void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if (x == y) return;
        par[x] = y;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        init();

        Node[] node = new Node[maxn];
        for (int i = 1; i <= n; i++) {
            node[i] = new Node();
            node[i].x = sc.nextInt();
            node[i].y = sc.nextInt();
            node[i].id = i;
        }

        Arrays.sort(node, 1, n + 1, cmp1);

        int cnt = 0;
        Edge[] e = new Edge[maxn << 1];
        for (int i = 2; i <= n; i++) {
            e[cnt] = new Edge();
            e[cnt].u = node[i - 1].id;
            e[cnt].v = node[i].id;
            e[cnt].val = node[i].x - node[i - 1].x;
            cnt++;
        }

        Arrays.sort(node, 1, n + 1, cmp2);
        for (int i = 2; i <= n; i++) {
            e[cnt] = new Edge();
            e[cnt].u = node[i - 1].id;
            e[cnt].v = node[i].id;
            e[cnt].val = node[i].y - node[i - 1].y;
            cnt++;
        }

        Arrays.sort(e, 0, cnt);

        long ans = 0;
        for (int i = 0; i < cnt; i++) {
            int u = e[i].u, v = e[i].v, val = e[i].val;
            if (findpar(u) == findpar(v)) continue;
            unite(u, v);
            ans += val;
        }

        System.out.println(ans);
    }
}
// 
