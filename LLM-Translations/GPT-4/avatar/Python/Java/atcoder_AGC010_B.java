import java.util.Scanner;

public class atcoder_AGC010_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        scanner.close();

        long sum = 0;
        for (int i : a) {
            sum += i;
        }

        if (sum % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
        } else {
            long k = sum / (n * (n + 1) / 2);
            long[] diff = new long[n];
            for (int i = 0; i < n - 1; i++) {
                diff[i] = (k - a[i + 1] + a[i]) % n;
            }
            diff[n - 1] = (k - a[0] + a[n - 1]) % n;

            long sumDiff = 0;
            for (long i : diff) {
                sumDiff += i;
            }

            int countNonNegative = 0;
            for (int i = 0; i < n; i++) {
                if ((k - a[(i + 1) % n] + a[i]) / n >= 0) {
                    countNonNegative++;
                }
            }

            if (sumDiff == 0 && countNonNegative == n) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

// End of Code
