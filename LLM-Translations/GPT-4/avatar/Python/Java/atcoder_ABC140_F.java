
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC140_F {

    public static void main(String[] args) {
        System.out.println(solve());
    }

    public static String solve() {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        Integer[] S = new Integer[N];
        for (int i = 0; i < N; i++) {
            S[i] = scanner.nextInt();
        }
        scanner.close();

        Arrays.sort(S, (a, b) -> b - a);
        boolean[] flag = new boolean[S.length];
        Arrays.fill(flag, true);

        ArrayList<Integer> cur = new ArrayList<>();
        cur.add(S[0]);
        flag[0] = false;

        for (int i = 0; i < N; i++) {
            int j = 0, jM = cur.size();
            for (int k = 0; k < S.length; k++) {
                if (flag[k] && S[k] < cur.get(j)) {
                    cur.add(S[k]);
                    j++;
                    flag[k] = false;
                    if (j == jM) {
                        break;
                    }
                }
            }

            if (j != jM) {
                return "No";
            }

            cur.sort((a, b) -> b - a);
        }

        return "Yes";
    }
}

// End of Code.
