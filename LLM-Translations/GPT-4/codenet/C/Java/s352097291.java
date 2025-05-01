
import java.util.Scanner;

public class s352097291 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) != 'B') {
                ans.append(input.charAt(i));
            } else {
                if (ans.length() > 0) {
                    ans.deleteCharAt(ans.length() - 1);
                }
            }
        }
        System.out.println(ans.toString());
    }
}

// 
