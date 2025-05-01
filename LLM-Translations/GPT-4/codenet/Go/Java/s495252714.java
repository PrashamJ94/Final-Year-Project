
import java.util.*;
import java.io.*;

public class s495252714 {
    static FastReader sc = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);
    static int mod = 1000000007;

    public static void main(String[] args) {
        int n = sc.nextInt();
        Integer[] c = new Integer[n];
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
        }

        int ans = 0;
        Arrays.sort(c);

        for (int i = 0; i < n; i++) {
            ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
        }

        out.println((ans * modPow(4, n - 1)) % mod);
        out.flush();
    }

    static int modPow(int a, int n) {
        int res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = (int)(((long)res * a) % mod);
            }
            a = (int)(((long)a * a) % mod);
            n >>= 1;
        }
        return res;
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
