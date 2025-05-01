import java.util.Arrays;
import java.util.Scanner;

public class s706119740 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] candy = new int[3];
        for (int i = 0; i < 3; i++) {
            candy[i] = scanner.nextInt();
        }
        scanner.close();

        Arrays.sort(candy);
        if (candy[0] + candy[1] == candy[2]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 
