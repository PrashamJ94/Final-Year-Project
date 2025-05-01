
import java.util.Scanner;

public class s175895052 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.next();

        if (((n.charAt(0) == n.charAt(1)) && (n.charAt(1) == n.charAt(2))) || ((n.charAt(1) == n.charAt(2)) && (n.charAt(2) == n.charAt(3)))) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// 
