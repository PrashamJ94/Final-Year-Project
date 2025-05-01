
import java.util.*;
import java.io.*;

public class atcoder_ABC126_E {
    static int N, M;
    static ArrayList<Integer>[] edge;
    static boolean[] used;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edge = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            edge[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken()) - 1;
            int Y = Integer.parseInt(st.nextToken()) - 1;
            int Z = Integer.parseInt(st.nextToken()) - 1;
            edge[X].add(Y);
            edge[Y].add(X);
        }

        used = new boolean[N];
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                ans++;
                Queue<Integer> queue = new LinkedList<>();
                queue.add(i);
                while (!queue.isEmpty()) {
                    int node = queue.poll();
                    used[node] = true;
                    for (int nextNode : edge[node]) {
                        if (!used[nextNode]) {
                            queue.add(nextNode);
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}

