
import java.util.*;

public class atcoder_ABC151_A {
    static boolean debug = false;
    static String alphabet = "abcdefghijklmnopqrstuvwxyz";

    public static void log(String text) {
        if (debug) {
            System.out.println(text);
        }
    }

    public static char parseInput(String line) {
        debug = false;
        char c = line.charAt(0);
        return c;
    }

    public static char solve(char c) {
        int i = alphabet.indexOf(c);
        return alphabet.charAt(i + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char c = parseInput(scanner.nextLine());
        char result = solve(c);
        System.out.println(result);
        scanner.close();
    }
}
// End of Code


