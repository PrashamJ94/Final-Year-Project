
import java.util.Scanner;

public class s205656765 {
    public static void main(String[] args) {
        int X, A, B, C;
        int i = 0;
        int j = 0;
        int k = 0;
        int kosu = 0;

        Scanner scanner = new Scanner(System.in);

        // Read integers
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        X = scanner.nextInt();

        X = X / 50;

        for (i = 0; i <= A; i++) {
            for (j = 0; j <= B; j++) {
                for (k = 0; k <= C; k++) {
                    if (X == (10 * i) + (2 * j) + k) kosu++;
                }
            }
        }

        System.out.println(kosu);
    }
}

// 
