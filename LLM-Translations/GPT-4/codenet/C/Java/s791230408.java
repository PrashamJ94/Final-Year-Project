
import java.util.Scanner;

public class s791230408 {
    public static void main(String[] args) {
        int a, b, c, i, j, k;
        int max;

        Scanner scanner = new Scanner(System.in);
        j = scanner.nextInt();

        for (i = 0; i < j; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();

            max = a;
            k = 0;
            if (max <= b) {
                max = b;
                k = 1;
            }
            if (max <= c) {
                max = c;
                k = 2;
            }

            max = max * max;
            a = a * a;
            b = b * b;
            c = c * c;
            if (k == 0 && max == b + c) {
                System.out.println("YES");
            } else if (k == 1 && max == a + c) {
                System.out.println("YES");
            } else if (k == 2 && max == a + b) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

// 
