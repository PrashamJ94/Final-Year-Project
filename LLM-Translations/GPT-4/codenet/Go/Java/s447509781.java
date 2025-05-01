import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s447509781 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] s = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        boolean[] u = new boolean[n];
        long m = 0;
        long f;

        for (int c = 1; c < n - 1; c++) {
            f = 0;
            for (int k = 0; c < n - 1 - k * c; k++) {
                u[k * c] = true;
                if (u[n - 1 - k * c]) {
                    break;
                }
                f += s[n - 1 - k * c] + s[k * c];
                if (m < f) {
                    m = f;
                }
            }
            for (int k = 0; k * c < n - 1; k++) {
                u[k * c] = false;
            }
        }
        System.out.println(m);
    }
}
// 
