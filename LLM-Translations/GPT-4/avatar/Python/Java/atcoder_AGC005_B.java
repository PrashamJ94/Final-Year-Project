
import java.util.*;

public class atcoder_AGC005_B {

    public static int root(int x, int[] par) {
        return par[x] == x ? x : (par[x] = root(par[x], par));
    }

    public static boolean same(int x, int y, int[] par) {
        return root(x, par) == root(y, par);
    }

    public static void unite(int x, int y, int[] par, int[] rank, int[] size) {
        x = root(x, par);
        y = root(y, par);
        if (x != y) {
            if (rank[x] < rank[y]) {
                par[x] = y;
                size[y] += size[x];
            } else {
                par[y] = x;
                size[x] += size[y];
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int[] par = new int[n];
        int[] rank = new int[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }

        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }

        long c = 0;
        for (int k : b) {
            int l = 1, r = 1;
            if (k > 0 && a[k - 1] > a[k]) {
                l += size[root(k - 1, par)];
                unite(k - 1, k, par, rank, size);
            }
            if (k + 1 < n && a[k + 1] > a[k]) {
                r += size[root(k + 1, par)];
                unite(k + 1, k, par, rank, size);
            }
            c += (long) l * r * a[k];
        }

        System.out.println(c);
    }
}

// End of Code
