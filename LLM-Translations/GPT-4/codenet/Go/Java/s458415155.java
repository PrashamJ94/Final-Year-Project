import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s458415155 {

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
    }

    public static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        for (int i = 0; i < t.length; i++) {
            t[i] = Integer.MAX_VALUE;
        }

        t[0] = 0;
        for (int i = 1; i < n; i++) {
            int v = t[i - 1] + Math.abs(heights[i] - heights[i - 1]);
            if (v < t[i]) {
                t[i] = v;
            }
            if (i > 1) {
                v = t[i - 2] + Math.abs(heights[i] - heights[i - 2]);
                if (v < t[i]) {
                    t[i] = v;
                }
            }
        }

        return t[n - 1];
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }
        int ans = solve(n, heights);
        System.out.println(ans);
    }
}
// 
