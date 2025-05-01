import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class s550008428 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s, x, d = 2;
        s = scanner.nextInt();
        Set<Integer> a = new HashSet<>();
        a.add(s);

        while (true) {
            if (s % 2 == 0) {
                x = s / 2;
                if (a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            } else {
                x = 3 * s + 1;
                if (a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            }
            s = x;
            d++;
        }
    }
}
// 
