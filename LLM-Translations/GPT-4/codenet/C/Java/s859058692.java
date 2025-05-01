import java.util.Scanner;

public class s859058692 {
    public static void main(String[] args) {
        long sum = 0;
        int m, n, i, min = 0, max = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        for (i = 0; i < n; i++) {
            m = sc.nextInt();
            sum += m;
            if (i == 0) {
                min = m;
                max = m;
            }

            if (min > m) {
                min = m;
            }
            if (max < m) {
                max = m;
            }
        }
        System.out.printf("%d %d %d\n", min, max, sum);
    }
}
// 
