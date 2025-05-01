
import java.util.Scanner;

public class s099670837 {

    private static final int arraySize = 101;
    private static int n, ans;
    private static int[][] a = new int[arraySize][arraySize];

    public static void findAns(int i, int j, int sum) {
        if (i == 1 && j == n - 1 && sum + a[i][j] > ans) {
            ans = sum + a[i][j];
            return;
        }
        if (i == 0) {
            findAns(i + 1, j, sum + a[i][j]);
        }
        if (j + 1 < n) {
            findAns(i, j + 1, sum + a[i][j]);
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
        findAns(0, 0, 0);
        System.out.println(ans);
    }
}

// 
