import java.util.*;

public class s777789287 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(a, Collections.reverseOrder());
        double s = Arrays.stream(a).mapToInt(Integer::intValue).sum() / (double) (4 * m);
        if (a[m - 1] >= s) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
