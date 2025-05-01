
import java.util.Scanner;

public class atcoder_ABC125_C {
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int[][] ruiseki_lr(int[] array) {
        int n = array.length;
        int e = 0;
        int[][] result = new int[2][n + 1];
        int[] left = result[0];
        int[] right = result[1];

        for (int i = 0; i < n; i++) {
            left[i + 1] = gcd(left[i], array[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            right[i] = gcd(right[i + 1], array[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int[][] lr = ruiseki_lr(a);
        int[] left = lr[0];
        int[] right = lr[1];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(left[i], right[i + 1]), ans);
        }

        System.out.println(ans);
    }
}

// End of Code
