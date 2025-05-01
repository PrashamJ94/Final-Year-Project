
import java.util.Scanner;

public class codeforces_546_A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] tokens = input.nextLine().split(" ");
        int k = Integer.parseInt(tokens[0]);
        int n = Integer.parseInt(tokens[1]);
        int w = Integer.parseInt(tokens[2]);

        if (1 <= k && w <= 1000) {
            int total = 0;
            for (int i = 1; i <= w; i++) {
                total += i * k;
            }
            if (total > n) {
                System.out.println(total - n);
            } else {
                System.out.println(0);
            }
        }
    }
}

// End of Code
