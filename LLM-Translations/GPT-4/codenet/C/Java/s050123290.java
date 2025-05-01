
import java.util.Scanner;

public class s050123290 {
    public static final int N = 1000;

    public static void main(String[] args) {
        char[] su = new char[N];
        int susum = 0;
        int j = 0;

        Scanner scanner = new Scanner(System.in);
        while (true) {
            String input = scanner.nextLine();
            for (j = 0; j <= N; j++) {
                if (j < input.length()) {
                    su[j] = input.charAt(j);
                    susum = susum + (su[j] - '0');
                } else {
                    break;
                }
            }
            if (su[0] == '0') {
                break;
            }
            System.out.println(susum);
            susum = 0;
        }
        scanner.close();
    }
}

// 
