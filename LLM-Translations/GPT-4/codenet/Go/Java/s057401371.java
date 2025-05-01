
import java.util.Scanner;

public class s057401371 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        int d = 'a' - 'A';
        StringBuilder result = new StringBuilder();
        for (char c : s.toCharArray()) {
            char tmp = c;
            if ('A' <= c && c <= 'Z') {
                tmp = (char) (c + d);
            } else if ('a' <= c && c <= 'z') {
                tmp = (char) (c - d);
            }
            result.append(tmp);
        }
        System.out.println(result.toString());
    }
}

// 
