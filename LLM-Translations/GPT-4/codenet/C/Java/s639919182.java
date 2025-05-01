
import java.util.Scanner;

public class s639919182 {
    public static void main(String[] args) {
        int[] v = new int[10];
        int sum = 0;
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            v[i] = scanner.nextInt();
        }

        for (int i = 0; i < 10; i++) {
            sum += v[i];
        }

        System.out.println(sum);
    }
}

// 
