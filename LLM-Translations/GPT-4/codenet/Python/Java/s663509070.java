import java.util.Scanner;
import java.lang.Math;

public class s663509070 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        scanner.nextLine();

        int[][] mat = new int[N][D];
        for (int d = 0; d < N; d++) {
            for (int i = 0; i < D; i++) {
                mat[d][i] = scanner.nextInt();
            }
            scanner.nextLine();
        }

        int c = 0;
        for (int i = 0; i < mat.length - 1; i++) {
            for (int j = i + 1; j < mat.length; j++) {
                double dist = 0;
                for (int k = 0; k < D; k++) {
                    dist += Math.pow(mat[i][k] - mat[j][k], 2);
                }
                dist = Math.sqrt(dist);

                if ((int) dist == dist) {
                    c++;
                }
            }
        }
        System.out.println(c);
    }
}
// 
