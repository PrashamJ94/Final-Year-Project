import java.util.Arrays;
import java.util.Scanner;

public class s963048401 {

    private static final int mod = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        int[] xs = new int[n];
        xs[0] = as[0];
        int len = 1;
        for (int j = 1; j < n; j++) {
            int idx = Arrays.binarySearch(xs, 0, len, as[j]);
            if (idx < 0) {
                idx = -idx - 1;
            }
            if (idx == len) {
                xs[len++] = as[j];
            } else {
                xs[idx] = as[j];
            }
        }
        System.out.println(len);
    }
}
// 
