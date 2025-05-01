//java
import java.util.Scanner;

public class s951065247 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int[] l = new int[N];
        for (int i = 0; i < N; i++) {
            l[i] = scanner.nextInt();
        }
        System.out.println(dfs(N, 0, 0, 0, 0, A, B, C, l));
    }

    public static int dfs(int N, int cur, int a, int b, int c, int A, int B, int C, int[] l) {
        if (cur == N) {
            return (Math.abs(A - a) + Math.abs(B - b) + Math.abs(C - c) - 30) * (Math.min(Math.min(a, b), c) > 0 ? 1 : 0) + 1000000000 * (Math.min(Math.min(a, b), c) > 0 ? 0 : 1);
        }
        int noAdd = dfs(N, cur + 1, a, b, c, A, B, C, l);
        int addA = dfs(N, cur + 1, a + l[cur], b, c, A, B, C, l) + 10;
        int addB = dfs(N, cur + 1, a, b + l[cur], c, A, B, C, l) + 10;
        int addC = dfs(N, cur + 1, a, b, c + l[cur], A, B, C, l) + 10;

        return Math.min(Math.min(noAdd, addA), Math.min(addB, addC));
    }
}

// 
