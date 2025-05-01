//java
import java.util.Scanner;

public class s986062252 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();
        String t = scanner.nextLine();

        int gcd = gcd(n, m);
        long lcm = (long) n * m / gcd;

        boolean isValid = true;
        for (int i = 0; i < gcd; i++) {
            if (s.charAt(n / gcd * i) != t.charAt(m / gcd * i)) {
                isValid = false;
                break;
            }
        }

        System.out.println(isValid ? lcm : -1);
    }

    private static int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
// 


