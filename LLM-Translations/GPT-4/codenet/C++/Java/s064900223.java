
import java.util.Scanner;
import java.util.ArrayList;

public class s064900223 {
    public static void main(String[] args) {
        int i, n, ans;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        ArrayList<Integer> p = new ArrayList<Integer>(n);
        for (i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        ans = 0;
        for (i = 0; i < n - 1; i++) {
            if (p.get(i) == i + 1) {
                p.set(i + 1, p.get(i));
                ans += 1;
            }
        }
        if (p.get(n - 1) == n) {
            ans += 1;
        }
        System.out.println(ans);
    }
}
// 


