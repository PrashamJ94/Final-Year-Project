import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s648707342 {
    static class Arm {
        int l, r;

        Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Arm[] as = new Arm[n];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int l = sc.nextInt();
            as[i] = new Arm(x - l, x + l);
        }

        Arrays.sort(as, Comparator.comparingInt(a -> a.r));

        int ans = 1;
        int r = as[0].r;
        for (int i = 1; i < n; i++) {
            if (as[i].l >= r) {
                ans++;
                r = as[i].r;
            }
        }
        System.out.println(ans);
    }
}
// 
