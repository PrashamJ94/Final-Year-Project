import java.util.Scanner;
import java.util.Arrays;

public class atcoder_ABC118_C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int gcd = findGCD(A);
        System.out.println(gcd);
    }

    public static int findGCD(int[] A) {
        int result = A[0];
        for (int i = 1; i < A.length; i++) {
            result = gcd(result, A[i]);
        }
        return result;
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}
// End of Code
