import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s541050824 {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = null;

    static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static long max(long x, long y) {
        return x > y ? x : y;
    }

    static long min(long x, long y) {
        return x < y ? x : y;
    }

    static long divUp(long x, long y) {
        return (x + y - 1) / y;
    }

    public static void main(String[] args) throws IOException {
        int N = nextInt();
        long[] T = new long[N];
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            T[i] = nextLong();
            A[i] = nextLong();
        }
        long t = T[0], a = A[0];
        for (int i = 1; i < N; i++) {
            long r = max(divUp(t, T[i]), divUp(a, A[i]));
            t = T[i] * r;
            a = A[i] * r;
        }
        System.out.println(t + a);
    }
}
// 
