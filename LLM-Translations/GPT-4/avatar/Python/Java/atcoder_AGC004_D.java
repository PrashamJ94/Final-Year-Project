import java.util.*;

public class atcoder_AGC004_D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] aaa = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            aaa[i] = sc.nextInt() - 1;
        }
        sc.close();

        List<Set<Integer>> links = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            links.add(new HashSet<>());
        }

        for (int i = 0; i < aaa.length; i++) {
            int a = aaa[i];
            links.get(a).add(i);
        }

        int[] result = dfs(links, n, k, 0, 0);
        int ans = result[1];
        if (aaa[0] != 1) {
            ans += 1;
        }
        System.out.println(ans);
    }

    private static int[] dfs(List<Set<Integer>> links, int n, int k, int v, int p) {
        int height_from_leaf = 0;
        int cut_count = 0;

        for (int u : links.get(v)) {
            if (u == 0) {
                continue;
            }
            int[] res = dfs(links, n, k, u, v);
            int hgt = res[0];
            int cut = res[1];
            height_from_leaf = Math.max(height_from_leaf, hgt);
            cut_count += cut;
        }

        height_from_leaf += 1;
        if (p != 0 && height_from_leaf == k) {
            height_from_leaf = 0;
            cut_count += 1;
        }

        return new int[]{height_from_leaf, cut_count};
    }
}
// End of Code
