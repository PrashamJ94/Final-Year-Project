import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s534639230 {

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] D = new int[N];

        for (int i = 0; i < N; i++) {
            D[i] = scanner.nextInt();
        }

        int mod = 998244353;

        if (D[0] != 0) {
            System.out.println(0);
            return;
        }

        Map<Integer, Integer> cnt = new HashMap<>();

        for (int d : D) {
            cnt.put(d, cnt.getOrDefault(d, 0) + 1);
        }

        if (cnt.get(0) > 1) {
            System.out.println(0);
            return;
        }

        long res = 1;

        for (int i = 1; i <= getMax(D); i++) {
            if (cnt.getOrDefault(i - 1, 0) == 1) {
                continue;
            }
            res *= Math.pow(cnt.getOrDefault(i - 1, 0), cnt.getOrDefault(i, 0)) % mod;
            res %= mod;
        }

        System.out.println(res);
    }

    public static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
}
// 
