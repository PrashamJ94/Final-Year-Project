
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class atcoder_ABC107_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        ArrayList<Integer> lst_p = new ArrayList<>();
        ArrayList<Integer> lst_m = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int num = scanner.nextInt();
            if (num == 0) {
                K -= 1;
            } else if (num > 0) {
                lst_p.add(num);
            } else {
                lst_m.add(num);
            }
        }

        Collections.sort(lst_p);
        Collections.sort(lst_m, Collections.reverseOrder());

        System.out.println(check(K, lst_p, lst_m));
    }

    public static int check(int k, ArrayList<Integer> lst_p, ArrayList<Integer> lst_m) {
        int ans = (int) 1e9;
        int lastx = lst_p.size();
        int lasty = lst_m.size();

        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            }

            int p, m;
            if (j == 0) {
                p = 0;
            } else {
                p = lst_p.get(j - 1);
            }

            if (k - j == 0) {
                m = 0;
            } else {
                m = lst_m.get(lasty - (k - j));
            }

            ans = Math.min(ans, 2 * p + Math.abs(m), p + 2 * Math.abs(m));
        }

        return ans;
    }
}

