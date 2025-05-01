import java.util.Scanner;
import java.lang.Math;

public class atcoder_ABC133_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int d = sc.nextInt();
        int[][] points = new int[n][d];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = sc.nextInt();
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isIntegerDistance(points[i], points[j])) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }

    public static boolean isIntegerDistance(int[] x, int[] y) {
        double tmp = 0.0;

        for (int i = 0; i < x.length; i++) {
            tmp += Math.pow(x[i] - y[i], 2);
        }

        double dist = Math.sqrt(tmp);
        return dist == Math.floor(dist);
    }
}

// End of Code
