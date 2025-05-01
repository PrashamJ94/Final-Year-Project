
import java.util.Scanner;

public class s784517449 {
    static int[] A;
    static int n;

    /* Binary search */
    public static int binarySearch(int key) {
        int left = 0;
        int right = n;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (key == A[mid]) return 1; /* key found */
            if (key > A[mid]) left = mid + 1; /* search in the second half */
            else if (key < A[mid]) right = mid; /* search in the first half */
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i, q, k, sum = 0;
        n = scanner.nextInt();
        A = new int[n];
        for (i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        q = scanner.nextInt();
        for (i = 0; i < q; i++) {
            k = scanner.nextInt();
            if (binarySearch(k) == 1)
                sum++;
        }
        System.out.println(sum);
    }
}

// 
