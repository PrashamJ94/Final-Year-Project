import java.util.Arrays;
import java.util.Scanner;

public class s068639994 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] ls = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = scanner.nextInt();
        }
        int[] lsRev = Arrays.copyOf(ls, n);
        Arrays.sort(ls);
        Arrays.sort(lsRev);
        for (int i = 0; i < lsRev.length / 2; i++) {
            int temp = lsRev[i];
            lsRev[i] = lsRev[lsRev.length - 1 - i];
            lsRev[lsRev.length - 1 - i] = temp;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;

                int l = Arrays.binarySearch(ls, x);
                if (l < 0) {
                    l = -(l + 1);
                }
                while (l < n && ls[l] <= x) {
                    l++;
                }

                int r = Arrays.binarySearch(lsRev, y);
                if (r < 0) {
                    r = -(r + 1);
                }
                while (r < n && lsRev[r] >= y) {
                    r++;
                }
                r = n - r;

                int sum = r - l;
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                sum = Math.max(0, sum);
                ans += sum;
            }
        }

        ans /= 3;
        System.out.println(ans);
    }
}
// 
