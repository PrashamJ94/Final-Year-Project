import java.util.Arrays;
import java.util.Scanner;

public class s747093551 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int[] x = new int[N];
        int[] y = new int[M];

        for (int i = 0; i < N; i++) {
            x[i] = scanner.nextInt();
        }

        for (int i = 0; i < M; i++) {
            y[i] = scanner.nextInt();
        }

        int maxX = Arrays.stream(x).max().getAsInt();
        int maxY = Arrays.stream(y).min().getAsInt();
        System.out.println(Math.max(maxX, X) < Math.min(maxY, Y) ? "No War" : "War");
    }
}
// 
