import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s940603045 {

    public static void main(String[] args) throws IOException {
        FastReader in = new FastReader();
        String N = in.next();
        byte[] b = N.getBytes();
        int n = 0;

        for (int i = 0; i < b.length; i++) {
            n += (b[i] - '0');
        }
        int m = Integer.parseInt(N);
        if (m % n == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
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
