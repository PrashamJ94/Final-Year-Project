
import java.util.Scanner;

public class s201325376 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b, c, i, count;
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        count = 0;
        for (i = a; i <= b; i++) {
            if (c % i == 0)
                count++;
        }
        System.out.println(count);
    }
}

// 
