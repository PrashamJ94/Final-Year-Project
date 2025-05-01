import java.util.Scanner;

public class s218426876 {
    public static void main(String[] args) {
        int i, sum = 0;
        int flag = 0;
        String x;
        Scanner scanner = new Scanner(System.in);
        x = scanner.next();
        do {
            for (i = 0; i < x.length(); i++) {
                if (x.charAt(i) == 0) {
                    System.out.println(sum);
                    break;
                } else {
                    sum += x.charAt(i) - '0';
                }
            }
            sum = 0;
            x = scanner.next();
        } while (x.charAt(0) != '0');
    }
}
// 
