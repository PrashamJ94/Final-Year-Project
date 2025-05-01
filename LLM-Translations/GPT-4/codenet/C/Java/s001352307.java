
import java.util.Scanner;

public class s001352307 {
    public static void main(String[] args) {
        int W, N;
        int[][] input = new int[1024][2];
        int[][] ans = new int[1024][2];
        int i, j, t;
        Scanner sc = new Scanner(System.in);

        for (t = 0; ; t++) {
            for (i = 0; i < 1024; i++) {
                ans[i][0] = 0;
                ans[i][1] = 0;
                input[i][0] = 0;
                input[i][1] = 0;
            }

            W = sc.nextInt();
            N = sc.nextInt();
            if (W == 0)
                break;
            for (i = 0; i < N; i++) {
                input[i][0] = sc.nextInt();
                input[i][1] = sc.nextInt();
                sc.nextLine();
            }

            for (i = 0; i < N; i++) {
                for (j = 1023; j >= input[i][1]; j--) {
                    if (ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                        ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                        ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                    }
                }
            }

            for (j = 0; ans[W][0] == ans[W - j - 1][0]; j++) ;

            System.out.printf("Case %d:\n%d\n%d\n", t + 1, ans[W - j][0], ans[W - j][1]);
        }
    }
}

// 
