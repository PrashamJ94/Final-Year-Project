
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class s406008869 {

    static ArrayList<ArrayList<Integer>> e;
    static int n, m;

    public static void printEdge() {
        for (int i = 1; i < n + 1; i++) {
            System.out.print(i + ": ");
            for (int v : e.get(i)) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    public static int dfs(int v, boolean[] visited) {

        boolean comp = true;
        for (int i = 1; i < n + 1; i++) {
            if (!visited[i]) {
                comp = false;
            }
        }

        if (comp) {
            return 1;
        }

        int count = 0;
        for (int ne : e.get(v)) {
            if (visited[ne]) {
                continue;
            }
            visited[ne] = true;

            int rst = dfs(ne, visited);

            count += rst;
            visited[ne] = false;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        e = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            e.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            e.get(a).add(b);
            e.get(b).add(a);
        }

        boolean[] visited = new boolean[n + 1];
        Arrays.fill(visited, false);
        visited[1] = true;
        int count = dfs(1, visited);
        System.out.println(count);
    }
}

// 
