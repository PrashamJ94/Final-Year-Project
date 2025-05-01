import java.util.Scanner;

public class codeforces_154_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = sc.nextInt();
        sc.nextLine();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            String x = sc.nextLine();
            int a = 0, b = 0;
            for (char j : s.toCharArray()) {
                if (j == x.charAt(0)) {
                    a += 1;
                } else if (j == x.charAt(1)) {
                    b += 1;
                } else {
                    ans = ans + Math.min(a, b);
                    a = 0;
                    b = 0;
                }
            }
            ans = ans + Math.min(a, b);
        }
        System.out.println(ans);
    }
}
// End of Code
