
import java.util.Scanner;

public class s647939399 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char m;
        int a, b, i = 0;
        int[] c = new int[256];

        while (true) {
            a = scanner.nextInt();
            m = scanner.next().charAt(0);
            b = scanner.nextInt();

            if (m == '?') {
                break;
            }
            if (m == '+') {
                c[i] = a + b;
            }
            if (m == '-') {
                c[i] = a - b;
            }
            if (m == '*') {
                c[i] = a * b;
            }
            if (m == '/') {
                c[i] = a / b;
            }
            i++;
        }

        for (int j = 0; j < i; j++) {
            System.out.println(c[j]);
        }
    }
}
// 


