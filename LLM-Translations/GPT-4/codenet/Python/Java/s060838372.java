import java.util.Scanner;

public class s060838372 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume newline character
        String S = scanner.nextLine();
        char[] S_chars = S.toCharArray();

        if (S_chars[K - 1] == 'A') {
            S_chars[K - 1] = 'a';
        } else if (S_chars[K - 1] == 'B') {
            S_chars[K - 1] = 'b';
        } else {
            S_chars[K - 1] = 'c';
        }
        
        String ans = new String(S_chars);
        System.out.println(ans);
    }
}

// 
