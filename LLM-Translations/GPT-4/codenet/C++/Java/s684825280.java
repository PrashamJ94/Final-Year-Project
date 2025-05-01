import java.util.*;

public class s684825280 {

    public static final int SIZE = (100000 * 2) + 13;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        int[] cnt = new int[SIZE];

        for (int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            cnt[x]++;
        }

        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] > 0) {
                a.add(cnt[i]);
            }
        }

        int ans = 0;
        Collections.sort(a);
        int m = a.size() - k;
        for (int i = 0; i < m; ++i) {
            ans += a.get(i);
        }

        System.out.println(ans);
    }
}

// 
