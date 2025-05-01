
import java.util.Scanner;

public class atcoder_ABC158_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N, A, B, mod = 1000000007, ans = 0, rep, res;
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        sc.close();
        
        rep = N / (A + B);
        ans += rep * A;
        res = N - rep * (A + B);
        ans += Math.min(res, A);

        System.out.println(ans);
    }
}

//End of Code
