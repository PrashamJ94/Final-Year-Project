
import java.util.Scanner;

public class s753632359 {
    public static void main(String[] args) {
        int N, D; // N, D are integers between 1 and 20
        int ans, rem;

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        D = sc.nextInt();

        ans = N / (D * 2 + 1);
        rem = N % (D * 2 + 1);

        if (rem != 0) {
            ans = ans + 1;
        }

        System.out.println(ans);
    }
}


