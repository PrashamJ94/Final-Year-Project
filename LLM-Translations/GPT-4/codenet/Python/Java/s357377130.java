import java.util.Scanner;

public class s357377130 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int K = scanner.nextInt();

        if (A + K - 1 >= B - K + 1) {
            while (A <= B) {
                System.out.println(A);
                A++;
            }
        } else {
            int i = 0;
            while (i <= K - 1) {
                System.out.println(A + i);
                i++;
            }
            while (B - K + 1 <= B) {
                System.out.println(B - K + 1);
                K--;
            }
        }
    }
}
// 
