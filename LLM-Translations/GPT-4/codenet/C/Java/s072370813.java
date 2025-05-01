
import java.util.Scanner;

public class s072370813 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] A = new int[N];
        int[] sa = new int[N];
        int i;
        long sum = 0;
        long wa = 0;
        int ans;
        int shou;
        long min = 1123456789;

        for (i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            sum += A[i];
            wa += i + 1;
        }

        if (sum % wa != 0) {
            ans = 0;
        } else {
            shou = (int) (sum / wa);
            for (i = 0; i < N; i++) {
                sa[i] = A[(i + 1) % N] - A[i] - shou;
            }

            for (i = 0; i < N - 1; i++) {
                if (sa[i] <= 0 && sa[i] % N == 0) {
                    ans = 1;
                } else {
                    ans = 0;
                    break;
                }
            }
        }

        if (ans == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

// 
