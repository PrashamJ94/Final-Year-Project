
import java.util.Scanner;

public class s860472409 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N, ans, i, count;
        N = sc.nextInt();
        int[] A = new int[N];
        for (i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        i = 0;
        ans = 0;
        count = 0;
        while (i + 1 < N) {
            if (A[i] == A[i + 1]) {
                count++;
                if (count % 2 != 0)
                    ans++;
            } else
                count = 0;
            i++;
        }

        System.out.println(ans);
    }
}

// 
