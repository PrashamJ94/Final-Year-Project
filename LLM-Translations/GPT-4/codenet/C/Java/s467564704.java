
import java.util.Scanner;

public class s467564704 {
    public static void main(String[] args) {
        int[][] input = new int[4][4];
        int tc;
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = sc.nextInt();
            }
        }

        tc = sc.nextInt();

        for (int t = 0; t < tc; t++) {
            int testcase = sc.nextInt();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (input[i][j] == testcase) {
                        input[i][j] = 0;
                    }
                }
            }
        }

        if (input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0) {
            System.out.println("Yes");
        } else if (input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0) {
            System.out.println("Yes");
        } else if (input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0) {
            System.out.println("Yes");
        } else if (input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0) {
            System.out.println("Yes");
        } else if (input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0) {
            System.out.println("Yes");
        } else if (input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0) {
            System.out.println("Yes");
        } else if (input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0) {
            System.out.println("Yes");
        } else if (input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// 
