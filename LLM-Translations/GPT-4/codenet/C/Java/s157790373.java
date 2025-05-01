import java.util.Scanner;

public class s157790373 {

    static final int LEN = 300;
    static final int TRUE = 1;
    static final int FALSE = -1;

    static int n;
    static int[] A = new int[LEN];
    static int flag;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }

        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int M = sc.nextInt();
            flag = FALSE;

            solve(-1, M);
            if (flag == TRUE) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }

    static int solve(int i, int m) {
        if (i > n) return FALSE;
        else if (m < 0) return FALSE;
        else if (m == 0 || m - A[i + 1] == 0) {
            flag = TRUE;
            return TRUE;
        } else {
            // not use A[i]
            solve(i + 1, m);
            // use A[i]
            solve(i + 1, m - A[i]);
        }
        return 0;
    }
}
// 
