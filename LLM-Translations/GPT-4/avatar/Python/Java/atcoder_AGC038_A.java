
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class atcoder_AGC038_A {
    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int H = reader.nextInt();
        int W = reader.nextInt();
        int A = reader.nextInt();
        int B = reader.nextInt();
        solve(H, W, A, B);
    }

    public static void solve(int H, int W, int A, int B) {
        char[][] answer = new char[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < B) {
                    if (j < A) {
                        answer[i][j] = '0';
                    } else {
                        answer[i][j] = '1';
                    }
                } else {
                    if (j < A) {
                        answer[i][j] = '1';
                    } else {
                        answer[i][j] = '0';
                    }
                }
            }
        }
        for (int i = 0; i < H; i++) {
            System.out.println(new String(answer[i]));
        }
    }

    static public class atcoder_AGC038_A {
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


// End of Code.
