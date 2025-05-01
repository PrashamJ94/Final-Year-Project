import java.util.Arrays;
import java.util.Scanner;

public class s219662687 {

    public static void main(String[] args) {
        int INF = (int) Math.pow(10, 11);
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int Q = sc.nextInt();
        int[] s = new int[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;
        for (int i = 1; i <= A; i++) {
            s[i] = sc.nextInt();
        }

        int[] t = new int[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;
        for (int i = 1; i <= B; i++) {
            t[i] = sc.nextInt();
        }

        for (int i = 0; i < Q; i++) {
            int x = sc.nextInt();
            int b = Arrays.binarySearch(s, x);
            if (b < 0) b = ~b;
            int d = Arrays.binarySearch(t, x);
            if (d < 0) d = ~d;
            int res = INF;
            for (int S : new int[]{s[b - 1], s[b]}) {
                for (int T : new int[]{t[d - 1], t[d]}) {
                    int d1 = Math.abs(S - x) + Math.abs(T - S);
                    int d2 = Math.abs(T - x) + Math.abs(S - T);
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            System.out.println(res);
        }
        sc.close();
    }

    public static int abs(int x) {
        return Math.abs(x);
    }

    public static int min(int x, int y) {
        return Math.min(x, y);
    }

    public static int max(int x, int y) {
        return Math.max(x, y);
    }
}
// 
