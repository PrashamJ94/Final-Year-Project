//java
import java.util.Scanner;

public class s103029464 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        for (int i = N - 1; i >= 0; i--) {
            int tmp_sum = 0;
            for (int j = (i + 1) * 2 - 1; j < N; j += i + 1) {
                tmp_sum += B[j];
                tmp_sum %= 2;
            }
            B[i] = tmp_sum ^ A[i];
        }

        int count = 0;
        for (int b : B) {
            if (b == 1) {
                count++;
            }
        }
        
        System.out.println(count);
        
        for (int i = 0; i < B.length; i++) {
            if (B[i] == 1) {
                System.out.print((i + 1) + " ");
            }
        }
    }
}
// 


