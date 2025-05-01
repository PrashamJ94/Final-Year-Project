
import java.util.Scanner;

public class s198852827 {
    public static int abs(int x) {
        return x < 0 ? -x : x;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N, t, x, y, nx = 0, ny = 0, nt = 0;
        int i, j, k, tmp;
        N = sc.nextInt();
        boolean possible = true;
        for (i = 0; i < N; i++) {
            t = sc.nextInt();
            x = sc.nextInt();
            y = sc.nextInt();
            tmp = t - nt - (abs(x - nx) + abs(y - ny));
            if (tmp < 0 || tmp % 2 != 0) {
                possible = false;
                break;
            }
            nt = t;
            nx = x;
            ny = y;
        }
        if (possible) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// 
