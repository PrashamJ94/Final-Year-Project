import java.util.*;

public class s146177123 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean[][] seg = {
            {false, true, true, true, true, true, true},
            {false, false, false, false, true, true, false},
            {true, false, true, true, false, true, true},
            {true, false, false, true, true, true, true},
            {true, true, false, false, true, true, false},

            {true, true, false, true, true, false, true},
            {true, true, true, true, true, false, true},
            {false, true, false, false, true, true, true},
            {true, true, true, true, true, true, true},
            {true, true, false, true, true, true, true}
        };

        int n, t;
        boolean[] st = new boolean[7];
        while ((n = sc.nextInt()) != -1) {
            Arrays.fill(st, false);
            for (int i = 0; i < n; i++) {
                t = sc.nextInt();
                char[] ans = new char[8];
                for (int j = 0; j < 7; j++) {
                    ans[j] = st[j] ^ seg[t][j] ? '1' : '0';
                    st[j] = seg[t][j];
                }
                System.out.println(new String(ans));
            }
        }
    }
}
// 
