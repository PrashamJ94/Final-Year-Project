import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class atcoder_ABC123_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<int[]> menu = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            int m = scanner.nextInt();
            int e = m % 10;
            if (e == 0) {
                e = 10;
            }
            menu.add(new int[]{m, e});
        }

        menu.sort(Comparator.comparingInt(x -> x[1]));

        int ans = 0;
        for (int i = 1; i < menu.size(); i++) {
            ans += Math.ceil((double) menu.get(i)[0] / 10) * 10;
        }
        System.out.println(ans + menu.get(0)[0]);
    }
}
// End of Code
