import java.util.*;
import java.lang.Math;

public class s493522692 {
    // Util
    public static int maxInt(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    public static int minInt(int a, int b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 'S' has N occurrences, 'c' has M occurrences
        int N = sc.nextInt();
        int M = sc.nextInt();
        int tmp = minInt(N, M / 2);
        int ans = 0;
        ans += tmp;
        N -= tmp;
        M -= tmp * 2;
        // System.out.println(ans + " " + N + " " + M);
        System.out.println(ans + M / 4);
    }
}
// 
