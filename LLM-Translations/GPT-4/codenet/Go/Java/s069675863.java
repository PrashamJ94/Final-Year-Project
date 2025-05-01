
import java.io.*;
import java.util.*;

public class s069675863 {
    static FastScanner sc = new FastScanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        char[] S = sc.next().toCharArray();
        int x = sc.nextInt();
        int y = sc.nextInt();

        ArrayList<Integer> F = new ArrayList<>();
        int cur = 0;
        for (int i = 0; i < S.length; i++) {
            if (S[i] == 'F') {
                cur++;
            } else {
                F.add(cur);
                cur = 0;
            }
        }
        F.add(cur);

        ArrayList<Integer> evens = new ArrayList<>();
        ArrayList<Integer> odds = new ArrayList<>();
        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens.add(F.get(i));
            } else {
                odds.add(F.get(i));
            }
        }

        boolean[][] dpx = new boolean[8000][20000];
        boolean[][] dpy = new boolean[8000][20000];
        dpx[0][10000] = dpy[0][10000] = true;
        for (int i = 0; i < evens.size(); i++) {
            int val = evens.get(i);
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
                }
                if (j - val >= 2000 && i != 0) {
                    dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
                }
            }
        }
        for (int i = 0; i < odds.size(); i++) {
            int val = odds.get(i);
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
                }
                if (j - val >= 2000) {
                    dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
                }
            }
        }

        if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
            out.println("Yes");
        } else {
            out.println("No");
        }

        out.flush();
    }

    static class FastScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        public double[] nextDoubleArray(int n) {
            double[] a = new double[n];
            for (int i = 0; i < n; i++)
                a[i] = nextDouble();
            return a;
        }
    }
}

// 
