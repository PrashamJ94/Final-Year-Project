import java.util.Scanner;
import java.util.Arrays;

public class s752993784 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        char[] s = input.toCharArray();
        int[] mods = new int[s.length];
        int[] countRemainder = new int[2019];
        int cnt = 0;

        int m = 1;
        int mod = 0;
        for (int i = 0; i < s.length; i++) {
            mod += Character.getNumericValue(s[s.length - i - 1]) * m;

            mod %= 2019;
            m *= 10;
            m %= 2019;

            countRemainder[mod] += 1;
        }

        countRemainder[0] += 1;

        for (int i = 0; i < 2019; i++) {
            cnt += countRemainder[i] * (countRemainder[i] - 1) / 2;
        }

        System.out.println(cnt);
    }
}
// 
