
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s684434772 {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int n = sc.nextInt();
        int k = sc.nextInt();

        long total = 0;
        for (int i = k; i <= n + 1; i++) {
            total += combi(n, i);
            total = total % (pow(10, 9) + 7);
        }
        System.out.println(total);
    }

    public static long combi(int n, int k) {
        long min = (long) (k - 1) * (long) k / 2;
        long max = (long) (2 * n - k + 1) * (long) k / 2;
        return max - min + 1;
    }

    // Utility functions
    public static int abs(int x) {
        return x >= 0 ? x : -x;
    }

    public static int min(int... values) {
        int min = Integer.MAX_VALUE;
        for (int v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static int max(int... values) {
        int max = Integer.MIN_VALUE;
        for (int v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    public static int pow(int base, int exponent) {
        int answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    public static long abs64(long x) {
        return x >= 0 ? x : -x;
    }

    public static long min64(long... values) {
        long min = Long.MAX_VALUE;
        for (long v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static long max64(long... values) {
        long max = Long.MIN_VALUE;
        for (long v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    public static long pow(long base, int exponent) {
        long answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    // Scanner
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}

// 
