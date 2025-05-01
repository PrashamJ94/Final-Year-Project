import java.util.Scanner;

public class atcoder_ABC145_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();

        if (n % 2 != 0) {
            System.out.println("No");
        } else {
            if (s.substring(0, n / 2).equals(s.substring(n / 2))) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
// End of Code
