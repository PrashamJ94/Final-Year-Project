
import java.util.*;

public class atcoder_ABC107_D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = n * (n + 1) / 4;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println(solve(n, m, a));
    }

    public static int solve(int n, int m, int[] a) {
        Set<Integer> set = new HashSet<>();
        set.add(0);
        for (int x : a) {
            set.add(x);
        }
        List<Integer> _a = new ArrayList<>(set);
        Collections.sort(_a);
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }
        int[] t = { _a.size(), 0 };
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            t[check(mid, n, a, m) ? 0 : 1] = mid;
        }
        return _a.get(t[1]);
    }

    public static boolean check(int X, int n, int[] a, int m) {
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1);
        }
        int c = Arrays.stream(b).min().getAsInt();
        for (int i = 0; i <= n; i++) {
            b[i] -= c;
        }
        BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2);
        int ans = 0;
        for (int x : b) {
            ans += bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    }
}

public class atcoder_ABC107_D {
    int size;
    int[] tree;

    public BIT(int N) {
        size = N;
        tree = new int[N + 1];
    }

    private int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    public int bitsum(int l, int r) {
        return _bitsum(r) - _bitsum(l);
    }

    public int bitsum(int l) {
        return _bitsum(l);
    }

    public void bitadd(int i, int x) {
        i += 1;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
}


// End of Code
