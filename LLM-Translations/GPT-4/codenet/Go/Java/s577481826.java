
import java.util.Scanner;

public class s577481826 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

        int result = a + b;

        if (result < (a - b)) {
            result = a - b;
        }
        if (result < (a * b)) {
            result = a * b;
        }

        System.out.println(result);
    }
}

// 
