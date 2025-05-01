
import java.util.Scanner;

public class s783753345 {
    public static void main(String[] args) {
        int a, b;
        char S;
        Scanner input = new Scanner(System.in);

        while (true) {
            a = input.nextInt();
            S = input.next().charAt(0);
            b = input.nextInt();

            if (S == '+') System.out.println(a + b);
            if (S == '-') System.out.println(a - b);
            if (S == '*') System.out.println(a * b);
            if (S == '/') System.out.println(a / b);
            if (S == '?') break;
        }

        input.close();
    }
}

// 
