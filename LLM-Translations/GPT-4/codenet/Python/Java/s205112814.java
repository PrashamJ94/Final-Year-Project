import java.util.Scanner;

public class s205112814 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] gate_cond = new int[m][2];

        for (int i = 0; i < m; i++) {
            gate_cond[i][0] = scanner.nextInt();
            gate_cond[i][1] = scanner.nextInt();
        }

        int max_under_th = Integer.MIN_VALUE;
        int min_upper_th = Integer.MAX_VALUE;

        for (int[] l : gate_cond) {
            max_under_th = Math.max(max_under_th, l[0]);
            min_upper_th = Math.min(min_upper_th, l[1]);
        }

        if (min_upper_th - max_under_th >= 0) {
            System.out.println(min_upper_th - max_under_th + 1);
        } else {
            System.out.println(0);
        }
    }
}
// 
