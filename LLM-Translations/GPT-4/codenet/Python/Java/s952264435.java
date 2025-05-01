import java.util.Scanner;

public class s952264435 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[M];
        int A_sum = 0;

        for (int i = 0; i < M; i++) {
            A[i] = sc.nextInt();
            A_sum += A[i];
        }

        System.out.println(N - A_sum >= 0 ? N - A_sum : "-1");
    }
}
// 
