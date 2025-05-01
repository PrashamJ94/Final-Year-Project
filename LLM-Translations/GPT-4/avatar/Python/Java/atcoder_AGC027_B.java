import java.util.*;
import java.io.*;
import java.util.stream.*;

public class atcoder_AGC027_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split("\\s+");
        int N = Integer.parseInt(input[0]);
        int X = Integer.parseInt(input[1]);
        
        int[] A = Arrays.stream(br.readLine().split("\\s+"))
                        .mapToInt(Integer::parseInt)
                        .toArray();
                        
        long[] S = new long[N];
        S[0] = A[0];
        for (int i = 1; i < N; i++) {
            S[i] = S[i - 1] + A[i];
        }
        
        long ans = Long.MAX_VALUE;
        for (int k = 0; k < N; k++) {
            long E = k * (long)X;
            for (int j = N - 2 * k - 1; j >= 0; j -= k) {
                E += 2 * S[j];
            }
            ans = Math.min(ans, E);
        }
        
        System.out.println(ans + N * (long)X + 5 * S[N - 1]);
    }
}
// End of Code
