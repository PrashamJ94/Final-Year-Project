
import java.util.Scanner;

public class s123216992 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b;
        while (true) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            if (a == 0 && b == 0) break;
            if (b < a) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            System.out.println(a + " " + b);
        }
        scanner.close();
    }
}

// 
