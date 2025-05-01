import java.util.*;
import java.io.*;

public class s146561572 {
    static int N = (int) (2e5) + 10;
    static int K = (int) (2e6) + 10;
    static int MOD = (int) (1e9) + 7;
    static int INF = (int) (1e9) + 5;
    static long INF64 = 2 * (long) 1e18;

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        while (t-- > 0) {
            solve(in, out);
        }
        out.flush();
    }

    static void solve(FastReader in, PrintWriter out) {
        long ans = 0;
        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            ans += i * 1L * (n - i + 1);
        }
        for (int i = 1; i < n; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            int a = Math.max(u, v);
            int b = Math.min(u, v);
            ans -= b * 1L * (n - a + 1);
        }
        out.println(ans);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
// 
