
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class codeforces_624_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Integer[] a = Arrays.stream(br.readLine().split("\\s"))
                .map(Integer::parseInt)
                .toArray(Integer[]::new);
        int ans = 0;
        int pre = Integer.MAX_VALUE;
        Arrays.sort(a, Collections.reverseOrder());
        for (int j = 0; j < n; j++) {
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        System.out.println(ans);
    }
}

// End of Code
