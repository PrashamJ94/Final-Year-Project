import java.util.Scanner;

public class codeforces_412_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        String v = sc.nextLine();
        String[] d = {"LEFT", "RIGHT"};
        boolean f = k - 1 < n - k;
        int m = Math.min(k - 1, n - k);
        StringBuilder a = new StringBuilder();

        for (int i = 0; i < m; i++) {
            a.append(d[f ? 0 : 1]).append("\n");
        }

        for (int i : new int[]{v.length() - (f ? 1 : 0), -1, f ? 1 : -1}) {
            a.append("PRINT ").append(v.charAt(i)).append("\n");
            a.append(d[f ? 1 : 0]).append("\n");
        }

        System.out.print(a.substring(0, a.length() - 1));
    }
}
// End of Code
