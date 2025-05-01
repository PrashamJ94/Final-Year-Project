import java.util.Scanner;

public class s494300734 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();

        String ans = "No";
        if (s.indexOf('C') < s.lastIndexOf('F')) {
            ans = "Yes";
        }
        if (s.indexOf('C') < 0) {
            ans = "No";
        }

        System.out.println(ans);
    }
}
// 
