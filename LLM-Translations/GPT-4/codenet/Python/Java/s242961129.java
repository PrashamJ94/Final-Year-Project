//java
import java.util.Scanner;

public class s242961129 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N+2];
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextInt();
        }

        int ans = Math.abs(A[N+1]);
        A[N+1] = 0;
        int[] diff = new int[N];
        for (int i = 1; i <= N; i++) {
            int dif = Math.abs(A[i] - A[i-1]) + Math.abs(A[i] - A[i+1]) - Math.abs(A[i-1] - A[i+1]);
            ans += Math.abs(A[i] - A[i-1]);
            diff[i-1] = dif;
        }

        for (int i = 0; i < N; i++) {
            System.out.println(ans - diff[i]);
        }
    }
}

//
