
import java.util.Scanner;

public class s500706216 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] a = new int[200000];
        int[] tmpa = new int[200000];
        int[] light = new int[200010];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            int r, l;
            r = i - a[i];
            l = i + a[i];
            light[(r < 0 ? 0 : r)]++;
            light[(l + 1 > n ? n + 1 : l + 1)]--;
        }

        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                tmpa[j] = a[j];
                sum += light[j];
                a[j] = sum;
            }
            for (int j = 0; j < n; j++) {
                int r = j - tmpa[j];
                int l = j + tmpa[j];
                light[(r < 0 ? 0 : r)]--;
                light[(l + 1 > n ? n + 1 : l + 1)]++;
                r = j - a[j];
                l = j + a[j];
                light[(r < 0 ? 0 : r)]++;
                light[(l + 1 > n ? n + 1 : l + 1)]--;
            }
            boolean isSame = true;
            for (int j = 0; j < n - 1; j++) {
                if (a[j] != a[j + 1]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame && a[0] == n) {
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            System.out.print(a[j]);
            System.out.print(j == n - 1 ? "\n" : " ");
        }
    }
}

// 
