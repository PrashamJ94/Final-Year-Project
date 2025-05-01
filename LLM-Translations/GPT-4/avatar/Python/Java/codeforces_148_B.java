
import java.util.Scanner;

public class codeforces_148_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int princess = scanner.nextInt();
        int dragon = scanner.nextInt();
        int t = scanner.nextInt();
        int f = scanner.nextInt();
        int c = scanner.nextInt();

        if (dragon <= princess) {
            System.out.println(0);
            System.exit(0);
        }

        int result = 0;
        double position = t * (double) princess;
        position += princess * position / (dragon - princess);

        while (position < c) {
            result += 1;
            position += princess * position / dragon;
            position += princess * f;
            position += princess * position / (dragon - princess);
        }

        System.out.println(result);
    }
}
// End of Code

