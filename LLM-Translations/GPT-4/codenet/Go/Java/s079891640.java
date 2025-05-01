
import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class s079891640 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Set<Character> uniqueChars = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (uniqueChars.contains(c)) {
                System.out.println("no");
                System.exit(0);
            }
            uniqueChars.add(c);
        }

        System.out.println("yes");
    }
}


