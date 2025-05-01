import java.util.Scanner;

public class s398580870 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.close();

        if (k % 2 == 1) {
            System.out.println((int) Math.pow(n / k, 3));
        } else {
            System.out.println((int) Math.pow(n / k, 3) + (int) Math.pow((n + k / 2) / k, 3));
        }
    }
}
// 
