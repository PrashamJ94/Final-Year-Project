import java.util.Arrays;
import java.util.Scanner;

class Edge {
    long s, g, c;

    Edge(long s, long g, long c) {
        this.s = s;
        this.g = g;
        this.c = c;
    }
}

class Graph {
    int vcnt, ecnt;
    Edge[] e;
    int[] id;

    Graph(int n) {
        this.vcnt = n;
        this.ecnt = 2 * n - 2;
        this.e = new Edge[2 * n];
        this.id = new int[n + 1];
    }
}

public class s073208348 {

    static void readGraph(Graph g, Scanner sc) {
        long n = sc.nextLong();
        for (int i = 0; i < n - 1; i++) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            long c = sc.nextLong();
            g.e[2 * i] = new Edge(x, y, c);
            g.e[2 * i + 1] = new Edge(y, x, c);
        }
        Arrays.sort(g.e, (a, b) -> {
            if (a.s != b.s) return Long.compare(a.s, b.s);
            return Long.compare(a.g, b.g);
        });

        int p = 0;
        for (int i = 0; i < g.vcnt; i++) {
            while (p < g.ecnt && g.e[p].s < i) p++;
            g.id[i] = p;
        }
        g.id[g.vcnt] = g.ecnt;
    }

    static int[] tyokkeitemp;
    static void tyokkeidfs(Graph g, long s) {
        for (int i = g.id[(int) s]; i < g.id[(int) s + 1]; i++) {
            if (tyokkeitemp[(int) g.e[i].g] == 0) {
                tyokkeitemp[(int) g.e[i].g] = tyokkeitemp[(int) s] + (int) g.e[i].c;
                tyokkeidfs(g, g.e[i].g);
            }
        }
    }

    static int tyokkei(Graph g) {
        tyokkeitemp = new int[g.vcnt + 10];
        tyokkeitemp[0] = 1;
        tyokkeidfs(g, 0);
        int M = 0, Mi = 0;
        for (int i = 0; i < g.vcnt; i++) {
            if (tyokkeitemp[i] > M) {
                M = tyokkeitemp[i];
                Mi = i;
            }
        }
        Arrays.fill(tyokkeitemp, 0);
        tyokkeitemp[Mi] = 1;
        tyokkeidfs(g, Mi);
        for (int i = 0; i < g.vcnt; i++) M = Math.max(M, tyokkeitemp[i]);
        return M - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        Graph g = new Graph((int) n);
        readGraph(g, sc);
        System.out.println(tyokkei(g));
    }
}
// 
