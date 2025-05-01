import java.util.Scanner;
import java.util.ArrayList;

public class s663381244 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> m = new ArrayList<>();
        m.add(10);
        m.add(50);
        m.add(100);
        m.add(500);

        boolean first = true;
        while (true) {
            int money = sc.nextInt();
            if (money == 0) {
                break;
            }

            if (!first) {
                System.out.println();
            }

            first = false;
            int sum = 0;
            ArrayList<Integer> num = new ArrayList<>(4);
            for (int i = 0; i < 4; ++i) {
                num.add(sc.nextInt());
                sum += num.get(i) * m.get(i);
            }

            int change = sum - money;
            for (int i = 3; i >= 0; --i) {
                if (change / m.get(i) > 0) {
                    num.set(i, num.get(i) - change / m.get(i));
                    change %= m.get(i);
                }
            }

            for (int i = 0; i < 4; ++i) {
                if (num.get(i) > 0) {
                    System.out.println(m.get(i) + " " + num.get(i));
                }
            }
        }
        sc.close();
    }
}
// 
