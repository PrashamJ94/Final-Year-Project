import java.util.Arrays;
import java.util.Scanner;

public class s390866994 {

    private static int getInt(Scanner sc) {
        return sc.nextInt();
    }

    private static int max(int a, int b) {
        return a > b ? a : b;
    }

    private static int min(int a, int b) {
        return a < b ? a : b;
    }

    private static int asub(int a, int b) {
        return a > b ? a - b : b - a;
    }

    private static int abs(int a) {
        return a >= 0 ? a : -a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = getInt(sc);
        int C = getInt(sc);
        int K = getInt(sc);
        int[] t = new int[N];
        for (int i = 0; i < N; i++) {
            t[i] = getInt(sc);
        }

        Arrays.sort(t);
        int ans = 1;
        int cnt = 1;
        int end = t[0] + K;
        for (int i = 1; i < N; i++) {
            if (cnt < C && t[i] <= end) {
                cnt++;
            } else {
                cnt = 1;
                end = t[i] + K;
                ans++;
            }
        }
        System.out.println(ans);
    }
}
// 
