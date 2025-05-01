import java.util.Scanner;

public class s387232787 {
    public static void main(String[] args) {
        int[] c = new int[26];
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String str = scanner.next();
            for (char ch : str.toCharArray()) {
                if ('a' <= ch && ch <= 'z') {
                    c[ch - 'a']++;
                } else if ('A' <= ch && ch <= 'Z') {
                    c[ch - 'A']++;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            System.out.printf("%c : %d\n", 'a' + i, c[i]);
        }
    }
}
// 
