import java.util.Scanner;

public class s844088973 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int X = scanner.nextInt();
        scanner.close();

        for (int i = X - K + 1; i <= X + K - 1; i++) {
            System.out.print(i);
            if (i < X + K - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
// 
