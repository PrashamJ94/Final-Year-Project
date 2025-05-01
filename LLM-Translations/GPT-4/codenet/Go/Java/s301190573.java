
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s301190573 {
    static int size = 1000000;
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        int n, m;
        String[] input = nextLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        int[] p = nextIntArray();
        int x, y;
        initialize(n);
        for (int i = 0; i < m; i++) {
            input = nextLine().split(" ");
            x = Integer.parseInt(input[0]) - 1;
            y = Integer.parseInt(input[1]) - 1;
            unite(x, y);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i])) {
                s++;
            }
        }
        System.out.println(s);
    }

    static int[] par, rank;

    static void initialize(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    static int root(int i) {
        if (par[i] == i) {
            return i;
        }
        par[i] = root(par[i]);
        return par[i];
    }

    static boolean same(int i, int j) {
        return root(i) == root(j);
    }

    static void unite(int i, int j) {
        i = root(i);
        j = root(j);
        if (i == j) {
            return;
        }
        if (rank[i] < rank[j]) {
            par[i] = j;
        } else {
            par[j] = i;
            if (rank[i] == rank[j]) {
                rank[i]++;
            }
        }
    }

    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int[] nextIntArray() throws IOException {
        tokenizer = new StringTokenizer(reader.readLine());
        int[] a = new int[tokenizer.countTokens()];
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(tokenizer.nextToken()) - 1;
        }
        return a;
    }
}

// 
