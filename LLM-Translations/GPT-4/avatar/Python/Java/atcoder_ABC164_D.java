import java.util.Scanner;

public class atcoder_ABC164_D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;
        int[] m = new int[l];
        m[0] = 1;
        int a = 0;
        int r = 0;
        for (int i = 0; i < s.length(); i++) {
            a += Character.getNumericValue(s.charAt(s.length() - 1 - i)) * powMod(10, i, l);
            r += m[a % l];
            m[a % l] += 1;
        }
        System.out.println(r);
    }

    private static int powMod(int base, int exponent, int mod) {
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result = (result * base) % mod;
        }
        return result;
    }
}
// End of Code
