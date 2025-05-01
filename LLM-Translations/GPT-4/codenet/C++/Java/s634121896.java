import java.io.*;
import java.util.*;

public class s634121896 {
    static final long INF = (long) 1e9 + 228;
    static final long INFLL = (long) 1e18;
    static final long MOD = (long) 1e9 + 7;
    static final double eps = 1e-6;
    static final double eps2 = 1e-9;
    static final long MOD2 = 998244353;
    static final long dosz = 5e5;
    static final long SZ = (1 << 18);
    static final double PI = Math.atan2(0, -1);

    public static void main(String[] args) {
        fast_io();
        int q = 1;
        // cin >> q;
        while (q-- > 0)
            solve();
    }

    static void fast_io() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    }

    static void solve() {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        List<Long> nums = new ArrayList<>(n);
        long last = 0;
        for (int i = 0; i < n; i++) {
            nums.add(sc.nextLong());
        }
        List<Long> dp = new ArrayList<>(n + 1);
        Collections.fill(dp, 0L);
        dp.set(0, 1L);
        Map<Long, Long> kek = new HashMap<>();
        Map<Long, Long> prev = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            dp.set(i, dp.get(i - 1) + (prev.get(nums.get(i - 1)) != i - 1 ? kek.get(nums.get(i - 1)) : 0));
            dp.set(i, dp.get(i) % MOD);
            kek.put(nums.get(i - 1), dp.get(i));
            prev.put(nums.get(i - 1), (long) i);
        }
        System.out.println(dp.get(n));
    }
}
// 
