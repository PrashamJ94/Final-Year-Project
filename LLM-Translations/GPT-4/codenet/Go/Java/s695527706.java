import java.util.Scanner;

public class s695527706 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        System.out.println(countABC(s));
    }

    public static int countABC(String s) {
        return s.length() - s.replace("ABC", "").length();
    }
}
// 
