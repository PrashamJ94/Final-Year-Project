import java.util.*;

class Main {
    static int[] readInts () {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ");
        int[] result = new int[line.length];
        for(int i = 0; i < line.length; i++)
            result[i] = Integer.parseInt(line[i]);
        return result;
    }

    static int[] dfs (Map<Integer, Set<Integer>> g, Set<Integer> seen, int i) {
        if(seen.contains(i))
            return new int[]{0, 0};
        seen.add(i);
        int nodes = 1;
        int edges = g.get(i).size();
        for(int j : g.get(i)){
            int[] result = dfs(g, seen, j);
            nodes += result[0];
            edges += result[1];
        }
        return new int[]{nodes, edges};
    }

    static void solve () {
        int[] line0 = readInts();
        int n = line0[0];
        int m = line0[1];
        Map<Integer, Set<Integer>> g = new HashMap<>();
        Set<Integer> seen = new HashSet<>();
        for(int i = 1; i <= n; i++)
            g.put(i, new HashSet<>());
        for(int i = 0; i < m; i++){
            int[] ints = readInts();
            int a = ints[0];
            int b = ints[1];
            g.get(a).add(b);
            g.get(b).add(a);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!seen.contains(i)){
                int[] result = dfs(g, seen, i);
                int nodes = result[0];
                int edges = result[1];
                if(nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges)
                    ans += 1;
            }
        }
        if((n - ans) % 2 == 1)
            ans += 1;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        while(true) {
            try {
                solve();
            } catch (Exception e) {
                break;
            }
        }
    }
}
// End of Code.
