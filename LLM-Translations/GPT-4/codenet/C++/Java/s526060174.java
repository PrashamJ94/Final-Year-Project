
import java.util.Scanner;

public class s526060174 {
    public static void main(String[] args) {
        int n, m, k, a;
        int[] x = new int[31];
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            k = sc.nextInt();
            for (int j = 0; j < k; ++j) {
                a = sc.nextInt();
                x[a]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            if (x[i] == n) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}

// 
