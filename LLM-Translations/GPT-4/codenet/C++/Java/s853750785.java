import java.util.*;
import java.io.*;

public class s853750785 {

    static int N, M;
    static int[] H = new int[100005];
    static ArrayList<Integer>[] G = new ArrayList[100005];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        for (int i = 0; i < N; i++) {
            H[i] = sc.nextInt();
        }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            if (G[u] == null) {
                G[u] = new ArrayList<>();
            }
            if (G[v] == null) {
                G[v] = new ArrayList<>();
            }
            G[u].add(v);
            G[v].add(u);
        }
        long ans = 0;
        for (int u = 0; u < N; u++) {
            boolean flag = true;
            if (G[u] != null) {
                for (int v : G[u]) {
                    if (H[u] <= H[v]) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
// 
