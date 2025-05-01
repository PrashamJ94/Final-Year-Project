import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s953070177 {

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
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();

        int n = sc.nextInt();

        int[] aa = new int[n + 2];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            aa[i + 1] = sc.nextInt();
            sum += Math.abs(aa[i + 1] - aa[i]);
        }
        sum += Math.abs(aa[n + 1] - aa[n]);

        for (int i = 1; i < n + 1; i++) {
            int ans = sum - Math.abs(aa[i + 1] - aa[i]) - Math.abs(aa[i] - aa[i - 1]) + Math.abs(aa[i + 1] - aa[i - 1]);
            System.out.println(ans);
        }
    }
}
// 
