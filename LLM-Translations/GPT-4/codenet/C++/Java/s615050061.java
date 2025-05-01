import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s615050061 {

    private static final long B = 13131;
    private static final int N = 500000 + 7;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String input = scanner.next();
        char[] s = new char[N];
        System.arraycopy(input.toCharArray(), 0, s, 1, input.length());

        long[] f = new long[N];
        int[] g = new int[N];
        Map<Long, Long> map = new HashMap<>();
        long cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
            } else {
                f[i] = f[i - 1];
                g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1);
            }
        }
        for (int i = n; i > 0; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1);
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L);
        }
        System.out.println(cnt);
    }

    private static long pow(long a, long k) {
        if (k < 0) {
            k += (1L << 63) - 1;
        }
        long t = 1;
        for (; k > 0; a = a * a, k >>= 1) {
            if ((k & 1) == 1) {
                t = t * a;
            }
        }
        return t;
    }

}

// 
