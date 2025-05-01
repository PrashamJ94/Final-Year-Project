
import java.util.Scanner;
import java.lang.Math;

public class s716011659 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] arrA = new int[n];
        for (int i = 0; i < n; i++) {
            arrA[i] = scanner.nextInt();
        }

        int[] cumSumA = new int[n + 1];
        cumSumA[0] = 0;
        for (int i = 0; i < n; i++) {
            cumSumA[i + 1] = cumSumA[i] + arrA[i];
        }

        double ans = 10000000000.0;
        for (int i = 1; i < n; i++) {
            if (Math.abs((double) (cumSumA[n] - (cumSumA[i] * 2))) < ans) {
                ans = Math.abs((double) (cumSumA[n] - cumSumA[i] * 2));
            }
        }

        System.out.println((int) ans);
    }
}

// 
