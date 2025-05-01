
import java.util.Scanner;

public class codeforces_99_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] splitInput = input.split("\\.");
        char[] s = splitInput[0].toCharArray();
        char[] p = splitInput[1].toCharArray();
        int i = Integer.parseInt(String.valueOf(p[0]));

        if (s[s.length - 1] == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (s[s.length - 1] != '9' && i < 5) {
            System.out.println(String.valueOf(s));
        } else {
            int sToInt = Integer.parseInt(String.valueOf(s));
            sToInt += 1;
            System.out.println(String.valueOf(sToInt));
        }
    }
}

End of Code.
