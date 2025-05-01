import java.util.*;
import java.math.*;

public class s814769071 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        long MOD = (long) 1e9 + 7;
        long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
        long mn = k * (k - 1) / 2;
        long res = 0;
        for (int i = (int) k; i <= n + 1; ++i) {
            res += mx - mn + 1;
            mx += n - i;
            mn += i;
            res %= MOD;
        }
        System.out.println(res);
    }
}
// 
