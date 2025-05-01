
import java.util.Scanner;

public class s977107185 {

    public static void main(String[] args) {

        int i, j, N, tmp, count = 0;
        int[] A = new int[100];
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        for (i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        for (i = 0; i < N - 1; i++) {

            for (j = N - 1; j > i; j--) {

                if (A[j] < A[j - 1]) {

                    tmp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;

                    count++;
                }
            }
        }

        for (i = 0; i < N; i++) {

            System.out.print(A[i]);

            if (i < N - 1) System.out.print(" ");

        }

        System.out.println();

        System.out.println(count);

    }
}

// 
