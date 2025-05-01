import java.util.Scanner;

public class s876834921 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        scanner.close();

        s = s.replace("dream", "D");
        s = s.replace("erase", "E");
        s = s.replace("Der", "");
        s = s.replace("Er", "");
        s = s.replace("D", "");
        s = s.replace("E", "");
        s = s.trim();

        if (s.isEmpty()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
// 
