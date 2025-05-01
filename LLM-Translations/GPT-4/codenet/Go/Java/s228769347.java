import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s228769347 {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));

        int n = nextInt();
        int[] ll = new int[n];

        for (int i = 0; i < n; i++) {
            ll[i] = nextInt();
        }

        Arrays.sort(ll);

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                        continue;
                    }
                    r = m;
                }

                ans += l - (j + 1);
            }
        }
        out.println(ans);

        out.flush();
    }

    static String nextString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}
// 
