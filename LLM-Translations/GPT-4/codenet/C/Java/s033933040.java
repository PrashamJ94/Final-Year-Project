
import java.util.Scanner;

public class s033933040 {
    public static void main(String[] args) {
        int a, b, mawari, menseki;

        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        mawari = a + a + b + b;
        menseki = a * b;

        System.out.printf("%d %d%n", menseki, mawari);
    }
}

// 
