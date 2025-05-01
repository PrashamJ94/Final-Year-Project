import java.util.Arrays;
import java.util.Scanner;

public class codeforces_299_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);
        int min = a[0];
        boolean flag = false;

        for (int x : a) {
            if (x % min != 0) {
                flag = true;
                break;
            }
        }

        System.out.println(flag ? -1 : min);

    }
}
// End of Code
