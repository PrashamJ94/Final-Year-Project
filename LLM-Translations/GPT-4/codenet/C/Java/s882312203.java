
import java.util.Scanner;

public class s882312203 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();

        boolean unique = true;

        for (int j = 0; j < s.length() && unique; j++) {
            for (int i = 0; i < s.length(); i++) {
                if ((i != j) && (s.charAt(i) == s.charAt(j))) {
                    unique = false;
                    break;
                }
            }
        }

        if (unique) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }
}

// 
