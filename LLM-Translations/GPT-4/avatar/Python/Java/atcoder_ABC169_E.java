public class atcoder_ABC169_E {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] low = new int[n];
        int[] high = new int[n];

        for (int i = 0; i < n; i++) {
            low[i] = scanner.nextInt();
            high[i] = scanner.nextInt();
        }

        java.util.Arrays.sort(low);
        java.util.Arrays.sort(high);

        if (n % 2 != 0) {
            System.out.println(high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
        } else {
            double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;
            double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;
            System.out.println((int) ((hh - ll) * 2) + 1);
        }

        scanner.close();
    }
}
// End of Code.
