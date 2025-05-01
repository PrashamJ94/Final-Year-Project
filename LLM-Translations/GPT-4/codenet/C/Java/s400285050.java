
import java.util.Scanner;

public class s400285050 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int y = in.nextInt();
        int z;

        if (x >= y) {
            z = you(x, y);
        } else {
            z = you(y, x);
        }

        System.out.println(z);
    }

    public static int you(int x, int y) {
        int z;
        while (true) {
            z = x % y;
            x = y;
            y = z;
            if (y <= 0) {
                break;
            }
        }
        return x;
    }
}
// 


