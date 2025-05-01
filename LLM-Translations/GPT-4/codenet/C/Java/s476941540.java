
import java.util.Scanner;

public class s476941540 {
    public static void main(String[] args) {
        int[] alpha = new int[26];
        char ch;
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 26; i++) alpha[i] = 0;

        while (sc.hasNext()) {
            ch = sc.next().charAt(0);
            if (Character.isAlphabetic(ch)) {
                if (Character.isUpperCase(ch)) alpha[ch - 65]++;
                else alpha[ch - 97]++;
            }
        }

        ch = 'a';
        for (int i = 0; i < 26; i++, ch++) {
            System.out.printf("%c : %d%n", ch, alpha[i]);
        }
    }
}

// 
