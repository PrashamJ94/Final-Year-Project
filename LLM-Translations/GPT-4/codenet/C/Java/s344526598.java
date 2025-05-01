
import java.util.Scanner;

public class s344526598 {
    public static void main(String[] args) {
        int i, j;
        int[] x = new int[10000];
        Scanner scanner = new Scanner(System.in);

        for (i = 0; i < 10000; i++) {
            x[i] = 0;
        }
        i = 0;
        x[i] = scanner.nextInt();

        while (x[i] != 0) {
            i++;
            x[i] = scanner.nextInt();
        }

        for (j = 0; j < i; j++) {
            System.out.printf("Case %d: %d%n", j + 1, x[j]);
        }

        scanner.close();
    }
}
// 


