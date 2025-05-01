import java.util.Scanner;

public class s031459110 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();
        String c = scanner.nextLine();

        int num_w = countOccurrences(c, 'W');
        int num_r = N - num_w;

        String comp = repeat('R', num_r) + repeat('W', num_w);
        int ans = 0;
        for (int i = 0; i < num_r; i++) {
            if (c.charAt(i) != comp.charAt(i)) {
                ans += 1;
            }
        }

        ans = Math.min(Math.min(num_w, num_r), ans);
        System.out.println(ans);
    }

    public static int countOccurrences(String str, char ch) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) {
                count++;
            }
        }
        return count;
    }

    public static String repeat(char ch, int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) {
            sb.append(ch);
        }
        return sb.toString();
    }
}
// 
