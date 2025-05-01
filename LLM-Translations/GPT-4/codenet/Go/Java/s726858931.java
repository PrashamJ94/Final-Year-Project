
import java.util.Scanner;

public class s726858931 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        char c = 'a';

        for (int j = 0; j < 26; j++) {
            boolean found = false;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println(Character.toString(c));
                return;
            }
            c++;
        }

        System.out.println("None");
    }
}


