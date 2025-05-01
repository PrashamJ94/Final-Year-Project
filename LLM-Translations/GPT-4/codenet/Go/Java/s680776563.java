
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s680776563 {
    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();
        int A = fs.nextInt();
        int B = fs.nextInt();
        int C = fs.nextInt();
        
        if (B - A == C - B) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
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
    }

    static int max(int a, int b) {
        return a < b ? b : a;
    }

    static long max(long a, long b) {
        return a < b ? b : a;
    }

    static double max(double a, double b) {
        return a < b ? b : a;
    }

    static int min(int a, int b) {
        return a > b ? b : a;
    }

    static long min(long a, long b) {
        return a > b ? b : a;
    }

    static double min(double a, double b) {
        return a > b ? b : a;
    }

    static int gcd(int a, int b) {
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (a < b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static int abs(int a) {
        return a < 0 ? -a : a;
    }

    static long abs(long a) {
        return a < 0 ? -a : a;
    }
}


