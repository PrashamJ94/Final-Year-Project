import java.util.Arrays;
import java.util.Scanner;

public class s154250720 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        while (in.hasNextInt()) {
            n = in.nextInt();
            int[] maps = new int[n + 1];
            int[] num = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                maps[i] = in.nextInt();
                num[i] = maps[i];
            }
            Arrays.sort(maps, 1, n + 1);
            int m = n / 2;
            for (int i = 1; i <= n; i++) {
                if (num[i] <= maps[m]) {
                    System.out.println(maps[m + 1]);
                } else {
                    System.out.println(maps[m]);
                }
            }
        }
        in.close();
    }
}
// 
