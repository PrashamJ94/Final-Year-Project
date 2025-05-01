import java.util.Scanner;

public class s636719275 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();

        int ans = (int) 1e6;
        for (int i = 0; i < s.length(); i++) {
            String a = s.substring(i);
            if (a.length() >= t.length()) {
                ans = Math.min(ans, check(t, a.substring(0, t.length())));
            }
        }
        System.out.println(ans);
    }

    public static int check(String a, String b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                count++;
            }
        }
        return count;
    }
}
// 
