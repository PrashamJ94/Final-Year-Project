
import java.util.*;

public class atcoder_ABC166_C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] p = new int[n + 1];
        int[] h = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            h[i] = in.nextInt();
        }
        HashMap<Integer, ArrayList<Integer>> path = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            path.put(i, new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            path.get(a).add(b);
            path.get(b).add(a);
        }
        int c = 0;
        for (Map.Entry<Integer, ArrayList<Integer>> entry : path.entrySet()) {
            int i = entry.getKey();
            ArrayList<Integer> v = entry.getValue();
            int f = 0;
            for (int j : v) {
                if (h[i] <= h[j]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                c++;
            }
        }
        System.out.println(c);
    }
}

// End of Code.
