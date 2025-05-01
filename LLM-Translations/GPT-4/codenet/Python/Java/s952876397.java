import java.util.Scanner;

public class s952876397 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();

        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                left += 1;
            } else {
                break;
            }
        }

        int left1 = 0;
        int right1 = 0;

        for (int i = left; i < n; i++) {
            if (s.charAt(i) == '(') {
                right1 += 1;
            } else if (right1 > 0) {
                right1 -= 1;
            } else {
                left1 += 1;
            }
        }

        left1 += left;
        for (int i = 0; i < right1; i++) {
            s += ")";
        }
        for (int i = 0; i < left1; i++) {
            s = "(" + s;
        }

        System.out.println(s);
    }
}
// 
