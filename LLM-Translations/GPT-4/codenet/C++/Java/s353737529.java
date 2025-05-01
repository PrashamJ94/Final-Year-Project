
import java.util.*;

public class s353737529 {
    static int[] dy = {-1, 0, +1, 0};
    static int[] dx = {0, +1, 0, -1};

    static final long INF = 1L << 60;
    static final long MOD = (long) 1e9 + 7;

    public static boolean greaterSecond(Pair<Integer, Integer> f, Pair<Integer, Integer> s) {
        return f.second > s.second;
    }

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = "";

        if (n == 0) {
            System.out.println('0');
            return;
        }

        int i = 1;
        while (n != 0) {
            if (n % 2 == 0) {
                s += '0';
            } else {
                s += '1';
            }

            n -= Math.abs(n % 2);

            n /= -2;
        }

        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        System.out.println(sb.toString());
    }
}

// 
