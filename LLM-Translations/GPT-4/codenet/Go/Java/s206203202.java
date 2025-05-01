
import java.util.Scanner;

public class s206203202 {

    public static int abs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    public static int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.close();

        int x = N % K;
        x = min(abs(x - K), x);
        System.out.println(x);
    }
}

// 
