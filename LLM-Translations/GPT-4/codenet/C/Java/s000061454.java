
import java.util.Scanner;

public class s000061454 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b, n;
        int sum;
        int i, j;
        while (scanner.hasNext()) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            n = scanner.nextInt();
            a -= a / b * b;
            sum = 0;
            for (i = 1; i <= n; i++) {
                a *= 10;
                for (j = 9; j >= 0; j--) {
                    if (b * j <= a) break;
                }
                a -= b * j;
                sum += j;
            }
            System.out.println(sum);
        }
        scanner.close();
    }
}
// 


