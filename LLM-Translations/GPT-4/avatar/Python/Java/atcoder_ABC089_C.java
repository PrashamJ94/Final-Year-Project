import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class atcoder_ABC089_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = br.readLine();
        }
        String[] march = { "M", "A", "R", "C", "H" };
        int[] march_lis = new int[5];
        for (String s : S) {
            String firstChar = s.substring(0, 1).toUpperCase();
            for (int i = 0; i < march.length; i++) {
                if (firstChar.equals(march[i])) {
                    march_lis[i]++;
                    break;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < march_lis.length; i++) {
            for (int j = i + 1; j < march_lis.length; j++) {
                for (int k = j + 1; k < march_lis.length; k++) {
                    ans += (long) march_lis[i] * march_lis[j] * march_lis[k];
                }
            }
        }
        System.out.println(ans);
    }
}
// End of Code.
