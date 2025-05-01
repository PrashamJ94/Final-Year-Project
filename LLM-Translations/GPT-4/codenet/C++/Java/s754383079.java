import java.util.Scanner;

public class s754383079 {
    static final int M = 1010;
    static char[] a = new char[M];
    static char[] b = new char[M];
    static int n, m, ans = M + 10;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String inputA = in.next();
        String inputB = in.next();

        a = inputA.toCharArray();
        b = inputB.toCharArray();

        n = a.length;
        m = b.length;

        for (int i = 1; i + m - 1 <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= m; j++) {
                if (a[i + j - 1] != b[j - 1]) {
                    sum++;
                }
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }
}
// 
