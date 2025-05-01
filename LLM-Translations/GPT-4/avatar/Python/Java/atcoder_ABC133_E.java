import java.util.*;

public class atcoder_ABC133_E {
    static int mod = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;

            graph.putIfAbsent(a, new ArrayList<>());
            graph.putIfAbsent(b, new ArrayList<>());

            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        sc.close();

        long ans = dfs(0, -1, K, graph);
        System.out.println(ans);
    }

    private static long dfs(int from, int to, int f, Map<Integer, List<Integer>> graph) {
        long caseNum = f;
        int colorNum = f == K ? K - 1 : K - 2;

        for (int u : graph.getOrDefault(from, Collections.emptyList())) {
            if (u == to) {
                continue;
            }
            long pat = dfs(u, from, colorNum, graph);
            if (pat == 0) {
                caseNum = 0;
                break;
            }
            caseNum = caseNum * pat % mod;
            colorNum -= 1;
        }
        return caseNum;
    }
}
// End of Code.
