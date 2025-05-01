import java.util.Scanner;

public class codeforces_231_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = 0;
        for (int i = 0; i < n; i++) {
            int l1 = sc.nextInt();
            int l2 = sc.nextInt();
            int l3 = sc.nextInt();
            if (l1 + l2 + l3 > 1) {
                c = c + 1;
            }
        }
        System.out.println(c);
    }
}
// End of Code
