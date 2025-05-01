import java.util.Scanner;

public class s628121241 {
    public static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int R = in.nextInt();

        if (R < 1200) {
            System.out.println("ABC");
        } else if (R >= 2800) {
            System.out.println("AGC");
        } else {
            System.out.println("ARC");
        }
    }
}
// 
