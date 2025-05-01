import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class codeforces_302_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine();

        String saInput = scanner.nextLine();
        int sa = saInput.length() - saInput.replace("-", "").length();
        sa = Math.min(n - sa, sa);

        List<String> ss = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            scanner.nextLine();

            b -= a;
            if (b % 2 != 0 && b <= sa * 2) {
                ss.add("1");
            } else {
                ss.add("0");
            }
        }

        for (String s : ss) {
            System.out.println(s);
        }
    }
}

// End of Code
