
import java.util.*;

public class s579031873 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long X = sc.nextLong();

        long ans = 0;
        long min = 1000000000;
        for (int i = 0; i < N; i++) {
            long tmp = sc.nextLong();
            X -= tmp;
            ans++;
            if (tmp < min) min = tmp;
        }

        ans += X / min;

        System.out.println(ans);
    }
}


