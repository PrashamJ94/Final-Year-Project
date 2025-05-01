
import java.util.Scanner;

public class s606068991 {

    public static void white(int n, int[] A) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println(A[n - 1]);
    }

    public static void insertionSort(int n, int[] A) {
        int i, j, a;
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (A[i] < A[j]) {
                    a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
            white(n, A);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, n;
        n = scanner.nextInt();
        int[] A = new int[100];
        for (i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        insertionSort(n, A);
    }
}

// 
