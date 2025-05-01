import java.util.Arrays;
import java.util.Scanner;

public class s384319383 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] cnt = new int[26];
        Arrays.fill(cnt, 1);
        char[] s = new char[n];
        final int MOD = (int) 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            s[i] = in.next().charAt(0);
            cnt[s[i] - 'a']++;
        }

        long ans = cnt[0];
        for (int i = 1; i < 26; ++i) {
            ans *= cnt[i];
            ans %= MOD;
        }

        System.out.println(ans - 1);
    }
}
// 
