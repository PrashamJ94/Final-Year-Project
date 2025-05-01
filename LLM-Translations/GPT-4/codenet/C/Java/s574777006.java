
import java.util.Scanner;

public class s574777006 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, i, j, q, sum = 0;
        int[] x = new int[10000];
        int[] y = new int[500];

        n = scanner.nextInt();

        for (i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }

        q = scanner.nextInt();

        for (i = 0; i < q; i++) {
            y[i] = scanner.nextInt();
        }

        for (i = 0; i < q; i++) {
            for (j = 0; j < n; j++) {
                if (y[i] == x[j]) {
                    sum = sum + 1;
                    break;
                }
            }
        }

        System.out.println(sum);
    }
}
// 

