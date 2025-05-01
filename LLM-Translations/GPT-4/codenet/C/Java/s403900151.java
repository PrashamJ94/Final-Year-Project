
import java.util.Scanner;

public class s403900151 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, r, p, c;
        int i, j, k, l;
        int[] a = new int[51];
        int[] b = new int[51];

        while (true) {
            n = sc.nextInt();
            r = sc.nextInt();
            if (n == 0 && r == 0)
                break;

            for (i = 0; i < n; i++)
                a[i] = i + 1;

            for (i = 0; i < r; i++) {
                p = sc.nextInt();
                c = sc.nextInt();

                for (j = 0; j < c; j++)
                    b[j] = a[n - p - c + 1 + j];
                for (j = 0; j < p - 1; j++)
                    a[n - p - c + 1 + j] = a[n - p + j + 1];
                for (j = n - p - c + 1 + j, k = 0; k < c; j++, k++) {
                    a[j] = b[k];
                }
            }
            System.out.println(a[n - 1]);
        }
        sc.close();
    }
}
// 


