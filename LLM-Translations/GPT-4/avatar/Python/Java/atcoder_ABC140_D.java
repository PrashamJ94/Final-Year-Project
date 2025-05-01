import java.util.*;

public class atcoder_ABC140_D {
    public static void main(String[] args) {
        Scanner input_parser = new Scanner(System.in);
        int MOD = (int) (1e9 + 7);
        int N = input_parser.nextInt();
        int K = input_parser.nextInt();
        input_parser.nextLine();
        String S = input_parser.nextLine();
        int seg_cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i) != S.charAt(i + 1)) {
                seg_cnt++;
            }
        }
        int cur_happy = N - 1 - seg_cnt;
        int ans;
        if (2 * K >= seg_cnt) {
            ans = N - 1;
        } else {
            ans = cur_happy + 2 * K;
        }
        System.out.println(ans);
    }
}
// End of Code
