
import java.util.Scanner;

public class s616182260 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] c = new int[3][3];
        int[] a = new int[3];
        int[] b = new int[3];
        int i, j;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                c[i][j] = sc.nextInt();
            }
        }

        a[0] = 0;
        for (i = 0; i < 3; i++) {
            b[i] = c[0][i];
        }
        for (i = 1; i < 3; i++) {
            a[i] = c[i][0] - b[0];
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (c[i][j] != a[i] + b[j]) {
                    System.out.println("No");
                    return;
                }
            }
        }
        System.out.println("Yes");
    }
}

// 
