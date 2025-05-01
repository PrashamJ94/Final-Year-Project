import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class s744854383 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            a.add(sc.nextInt());
        }

        int idx = 1;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (a.get(i) == idx) {
                idx++;
            } else {
                ans++;
            }
        }

        if (idx == 1) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }
}
// 
