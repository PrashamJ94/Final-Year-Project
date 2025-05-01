import java.util.Arrays;
import java.util.Scanner;

public class s846046431 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        sc.close();
        Arrays.sort(A);
        int S = 0;
        for (int a : A) {
            S += a;
        }
        for (int i = N - 1; i >= N - M; i--) {
            if ((double) A[i] / S - 1.0 / (4 * M) < 0) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
// 
