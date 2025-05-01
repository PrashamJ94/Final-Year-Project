
import java.util.Arrays;
import java.util.Scanner;

public class s441329208 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();

        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();

        Arrays.sort(sChars);
        Arrays.sort(tChars);

        String sortedS = new String(sChars);
        String sortedT = new StringBuilder(new String(tChars)).reverse().toString();

        System.out.println(sortedS.compareTo(sortedT) < 0 ? "Yes" : "No");
    }
}
// 

