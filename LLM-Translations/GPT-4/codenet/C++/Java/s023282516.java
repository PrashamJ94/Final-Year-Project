import java.util.*;

public class s023282516 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        String[] divide = {"dream", "dreamer", "erase", "eraser"};

        // Reverse the whole string
        S = new StringBuilder(S).reverse().toString();

        // Reverse each string in the divide array
        for (int i = 0; i < 4; ++i) {
            divide[i] = new StringBuilder(divide[i]).reverse().toString();
        }

        boolean can = true;
        for (int i = 0; i < S.length();) {
            boolean can2 = false; // Check if any of the 4 strings can be divided
            for (int j = 0; j < 4; ++j) {
                String d = divide[j];
                if (S.startsWith(d, i)) { // Check if it can be divided by d
                    can2 = true;
                    i += d.length(); // Move i forward if it can be divided
                }
            }
            if (!can2) { // If it cannot be divided
                can = false;
                break;
            }
        }

        if (can) System.out.println("YES");
        else System.out.println("NO");
    }
}
// 
