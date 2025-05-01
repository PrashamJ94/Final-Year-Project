import java.util.*;
import java.io.*;

public class atcoder_ABC146_D {
    static int bfs(int v, int N, ArrayList<Deque<Integer>> G, HashMap<SimpleImmutableEntry<Integer, Integer>, Integer> E) {
        int[] visited = new int[N];
        Deque<Integer> queue = new ArrayDeque<>();
        int K = -1;
        int[] node2color = new int[N];
        Arrays.fill(node2color, -1);
        queue.add(v);
        visited[v] = 1;

        while (!queue.isEmpty()) {
            int q = queue.poll();
            int color = 0;
            for (int nex : G.get(q)) {
                if (visited[nex] != 0) {
                    continue;
                }
                visited[nex] = 1;
                color += 1;
                if (color == node2color[q]) {
                    color += 1;
                }
                node2color[nex] = color;
                E.put(new AbstractMap.SimpleImmutableEntry<>(Math.min(q, nex), Math.max(q, nex)), color);
                queue.add(nex);
            }
            K = Math.max(K, color);
        }
        return K;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ArrayList<Deque<Integer>> G = new ArrayList<>();
        HashMap<AbstractMap.SimpleImmutableEntry<Integer, Integer>, Integer> E = new HashMap<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayDeque<>());
        }
        for (int i = 0; i < N - 1; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]) - 1;
            int b = Integer.parseInt(input[1]) - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(new AbstractMap.SimpleImmutableEntry<>(a, b), 0);
        }
        int K = bfs(0, N, G, E);
        System.out.println(K);
        for (int value : E.values()) {
            System.out.println(value);
        }
    }
}
// End of Code.
