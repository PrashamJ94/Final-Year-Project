
import java.util.Scanner;

public class s302860389 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String inputNumbers = sc.next();
        int a = Character.getNumericValue(inputNumbers.charAt(0));
        int b = Character.getNumericValue(inputNumbers.charAt(1));
        int c = Character.getNumericValue(inputNumbers.charAt(2));
        int d = Character.getNumericValue(inputNumbers.charAt(3));

        int sum;
        char[] symbols = new char[3];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (i == 0) {
                        sum = a + b;
                        symbols[0] = '+';
                    } else {
                        sum = a - b;
                        symbols[0] = '-';
                    }

                    if (j == 0) {
                        sum = sum + c;
                        symbols[1] = '+';
                    } else {
                        sum = sum - c;
                        symbols[1] = '-';
                    }

                    if (k == 0) {
                        sum = sum + d;
                        symbols[2] = '+';
                    } else {
                        sum = sum - d;
                        symbols[2] = '-';
                    }

                    if (sum == 7) {
                        System.out.printf("%d%c%d%c%d%c%d=7%n", a, symbols[0], b, symbols[1], c, symbols[2], d);
                        sc.close();
                        return;
                    }
                }
            }
        }

        sc.close();
    }
}

// 
