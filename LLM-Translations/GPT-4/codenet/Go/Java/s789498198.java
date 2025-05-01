
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s789498198 {

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner();
        int[] AB = sc.nextIntArray();
        int A = AB[0];
        int B = AB[1];

        if ((A + B) % 2 == 0) {
            System.out.println((A + B) / 2);
            return;
        }
        System.out.println("IMPOSSIBLE");
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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

        int[] nextIntArray() {
            int[] array = new int[st.countTokens()];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextInt();
            }
            return array;
        }

        long[] nextLongArray() {
            long[] array = new long[st.countTokens()];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextLong();
            }
            return array;
        }

        double[] nextDoubleArray() {
            double[] array = new double[st.countTokens()];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextDouble();
            }
            return array;
        }
    }
}

// 
