import java.util.Scanner;

public class s326049239 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, c, k, b;

        while (scanner.hasNextInt()) {
            a = scanner.nextInt();
            c = 0;
            k = 0;

            if (a < 3) {
                System.out.println("0");
            } else {
                b = a;
                while (a-- > 0) {
                    b--;
                    c++;
                    if (c == 3) {
                        k++;
                        c = 0;
                    }
                }
                System.out.println(k);
            }
        }
    }
}
// 
