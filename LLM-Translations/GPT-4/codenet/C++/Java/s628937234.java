
import java.util.Scanner;

public class s628937234 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s, t;
        s = scanner.next();
        t = s.charAt(0) + Integer.toString(s.length() - 2) + s.charAt(s.length() - 1);
        System.out.println(t);
    }
}

// 
