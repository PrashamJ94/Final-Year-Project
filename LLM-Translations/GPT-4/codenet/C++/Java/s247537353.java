
import java.util.Scanner;

public class s247537353 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A, B, C, K;
        A = sc.nextLong();
        B = sc.nextLong();
        C = sc.nextLong();
        K = sc.nextLong();

        if (A + B >= K) {
            System.out.println(Math.min(A, K));
        } else {
            System.out.println(A - (K - (A + B)));
        }
    }
}

// 
