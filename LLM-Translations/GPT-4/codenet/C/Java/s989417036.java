
import java.util.Scanner;

public class s989417036 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a, b, c, d, e, i;
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();

        if (b <= c) {
            System.out.println("NO");
            return;
        } else {
            d = a;
            e = d % b;
            for (i = 0; i < b; i++) {
                d = d % b;
                if (d == c) {
                    System.out.println("YES");
                    return;
                } else if (i != 0 && d == c) {
                    System.out.println("NO");
                    return;
                }
                d += a;
            }
        }
        System.out.println("NO");
    }
}

// 
