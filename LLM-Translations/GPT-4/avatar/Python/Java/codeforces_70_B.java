import java.util.*;
import java.util.regex.*;

public class codeforces_70_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // To clear the input buffer
        String input = sc.nextLine();
        int ans = 1, sumL = 0;
        String[] sentences = input.split("[.?!]");
        for (String s : sentences) {
            s = s.trim() + '.';
            int L = s.length();
            if (L > 1) {
                if (L > n) {
                    System.out.println("Impossible");
                    System.exit(0);
                }
                if (sumL + L + (sumL > 0) > n) {
                    ans++;
                    sumL = L;
                } else {
                    sumL = sumL + L + (sumL > 0);
                }
            }
        }
        System.out.println(ans);
    }
}

// End of Code.
