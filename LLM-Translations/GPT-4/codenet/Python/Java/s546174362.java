import java.util.Arrays;
import java.util.Scanner;

public class s546174362 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] A = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        Arrays.sort(A);

        while (M > 0) {
            A[N - 1] /= 2;
            M--;
            int i = -2;
            while (M > 0 && (-N <= i && A[N + i] >= A[N - 1])) {
                A[N + i] /= 2;
                M--;
                i--;
            }
            Arrays.sort(A);
        }

        int sum = 0;
        for (int a : A) {
            sum += a;
        }

        System.out.println(sum);
    }
}
// 
