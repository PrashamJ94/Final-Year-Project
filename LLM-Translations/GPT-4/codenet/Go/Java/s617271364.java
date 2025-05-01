import java.util.*;
import java.io.*;

public class s617271364 {
    static int N, ss, ans, A, B, C;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] X = br.readLine().split(" ");
        N = Integer.parseInt(X[0]);
        A = Integer.parseInt(X[1]);
        B = Integer.parseInt(X[2]);
        C = Integer.parseInt(X[3]);

        int[] arr = new int[N];
        int[] dp = new int[N];
        ans = 10000;
        ss = A + B + C;

        for (int i = 0; i < N; i++) {
            String[] Y = br.readLine().split(" ");
            arr[i] = Integer.parseInt(Y[0]);
        }

        dfs(dp, 0, arr);

        bw.write(ans + "\n");
        bw.flush();
    }

    static void dfs(int[] dp, int times, int[] arr) {
        if (times >= N) {
            ans = Math.min(ans, calc(dp, arr));
            return;
        }

        for (int i = 0; i < 4; i++) {
            dp[times] = i;
            dfs(dp, times + 1, arr);
        }
    }

    static int calc(int[] dp, int[] arr) {
        int cost, AA, BB, CC;
        cost = AA = BB = CC = 0;

        int[] memo = new int[4];
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++;
            if (dp[i] == 1) {
                AA += arr[i];
            } else if (dp[i] == 2) {
                BB += arr[i];
            } else if (dp[i] == 3) {
                CC += arr[i];
            }
        }
        cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);

        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000;
            } else {
                cost += (a - 1) * 10;
            }
        }

        return cost;
    }

}
// 
