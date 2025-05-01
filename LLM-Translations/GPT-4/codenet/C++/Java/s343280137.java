import java.util.Scanner;

public class s343280137 {

    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong();
        long c = scanner.nextLong();

        long[] x = new long[(int) (n + 1)];
        long[] v = new long[(int) (n + 1)];

        for (int i = 1; i < n + 1; i++) {
            x[i] = scanner.nextLong();
            v[i] = scanner.nextLong();
        }

        long[] leftTotal = new long[(int) (n + 1)];
        long[] maxLeftTotal = new long[(int) (n + 1)];
        for (int i = 1; i < n + 1; i++) {
            leftTotal[i] = leftTotal[i - 1] + v[i];
        }

        for (int i = 1; i < n + 1; i++) {
            maxLeftTotal[i] = Math.max(maxLeftTotal[i - 1], leftTotal[i] - x[i]);
        }

        long[] rightTotal = new long[(int) (n + 1)];
        long[] maxRightTotal = new long[(int) (n + 1)];
        for (int i = 1; i < n + 1; i++) {
            rightTotal[i] = rightTotal[i - 1] + v[(int) (n - i + 1)];
        }

        for (int i = 1; i < n + 1; i++) {
            maxRightTotal[i] = Math.max(maxRightTotal[i - 1], rightTotal[i] - (c - x[(int) (n + 1 - i)]));
        }

        long ans = 0;

        for (int i = 1; i < n + 1; i++) {
            ans = Math.max(ans, leftTotal[i] - x[i]);
            ans = Math.max(ans, leftTotal[i] - 2 * x[i] + maxRightTotal[(int) (n - i)]);
            ans = Math.max(ans, rightTotal[i] - (c - x[(int) (n + 1 - i)]));
            ans = Math.max(ans, rightTotal[i] - 2 * (c - x[(int) (n + 1 - i)]) + maxLeftTotal[(int) (n - i)]);
        }

        System.out.println(ans);
    }
}
// 
