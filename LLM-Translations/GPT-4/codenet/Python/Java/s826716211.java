import java.util.Arrays;

public class s826716211 {
    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        char[] S_d = input().toCharArray();
        char[] T = input().toCharArray();

        int end = S_d.length - 1;
        int first = end - T.length + 1;
        while (first >= 0) {
            int t_i = 0;
            for (int s_i = first; s_i <= end; s_i++) {
                if (T[t_i] != S_d[s_i] && S_d[s_i] != '?') {
                    break;
                }
                t_i++;
            }
            if (t_i == T.length) {
                break;
            }

            first--;
            end--;
        }

        if (first < 0) {
            System.out.println("UNRESTORABLE");
            System.exit(0);
        }

        char[] ans = Arrays.copyOf(S_d, S_d.length);
        int t_i = 0;
        for (int i = first; i <= end; i++) {
            ans[i] = T[t_i];
            t_i++;
        }

        String ans_str = new String(ans).replace('?', 'a');
        System.out.println(ans_str);
    }

    public static String input() {
        return System.console().readLine();
    }
}
// 
