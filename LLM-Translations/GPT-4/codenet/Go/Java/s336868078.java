
import java.util.Scanner;

public class s336868078 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();

        int ans = solve(a, b, c);
        System.out.println(ans);
    }

    public static int solve(int a, int b, int c) {
        int temp_;
        if (c == a + b) {
            temp_ = b + c;
        } else if (c - 1 > a + b) {
            int temp = (c - 1) - (a + b);
            temp_ = b + c - temp;
        } else {
            temp_ = b + c;
        }

        return temp_;
    }
}

// 
