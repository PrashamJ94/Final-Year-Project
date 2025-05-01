import java.util.Scanner;

public class atcoder_ABC178_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        System.out.println(maxProduct(a, b, c, d));
    }

    public static int maxProduct(int a, int b, int c, int d) {
        return Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c));
    }
}
// End of Code.
