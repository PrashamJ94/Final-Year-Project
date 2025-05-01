import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class s908812767 {
    static Map<Integer, List<int[]>> V = new HashMap<>(); // key:vertex, value:[[vertex opposited, weight]]
    static Map<Integer, Integer> color = new HashMap<>(); // 0 or 1 or -1

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 1; i < n; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            V.putIfAbsent(u, new ArrayList<>());
            V.get(u).add(new int[]{v, w});

            V.putIfAbsent(v, new ArrayList<>());
            V.get(v).add(new int[]{u, w});
        }

        for (int i = 1; i <= n; i++) {
            color.put(i, -1);
        }

        while (true) {
            int i = 0;
            for (int j = 1; j <= n; j++) {
                if (color.get(j) == -1) {
                    i = j;
                    color.put(i, 0);
                    break;
                }
            }

            if (i == 0) {
                for (int j = 1; j <= n; j++) {
                    System.out.println(color.get(j));
                }
                break;
            } else {
                if (!dfs(i)) {
                    System.out.println("No");
                    break;
                }
            }
        }
    }

    public static boolean dfs(int i) {
        for (int[] vw : V.getOrDefault(i, new ArrayList<>())) {
            int v = vw[0];
            int w = vw[1];

            if (w % 2 == 0) {
                if (color.get(v) == -1) {
                    color.put(v, color.get(i));
                } else if (color.get(v).equals(color.get(i))) {
                    continue;
                } else if (!color.get(v).equals(color.get(i))) {
                    return false;
                }
            } else {
                if (color.get(v) == -1) {
                    color.put(v, color.get(i) == 0 ? 1 : 0);
                } else if (color.get(v).equals(color.get(i))) {
                    return false;
                } else if (!color.get(v).equals(color.get(i))) {
                    continue;
                }
            }
            if (!dfs(v)) {
                return false;
            }
        }
        return true;
    }
}
// 
