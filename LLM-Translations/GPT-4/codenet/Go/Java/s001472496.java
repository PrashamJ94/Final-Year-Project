
import java.util.Scanner;

public class s001472496 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        
        int maxTmp = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            boolean flag = false;
            switch (s.charAt(i)) {
                case 'A':
                case 'C':
                case 'T':
                case 'G':
                    maxTmp++;
                    break;
                default:
                    flag = true;
            }

            if (i == s.length() - 1) {
                flag = true;
            }
            if (flag) {
                if (max < maxTmp) {
                    max = maxTmp;
                }
                maxTmp = 0;
            }
        }
        System.out.println(max);
    }
}

// 
