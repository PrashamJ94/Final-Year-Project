import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class atcoder_AGC028_B {
    static final int MOD = 1000000007;
    static final int M = 1000000;
    static final int Nsq = 1000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        long[][] fact = new long[Nsq][Nsq];
        fact[0][0] = 1;

        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[i][n] = fact[i][n - 1] * (i * Nsq + n);
                fact[i][n] %= MOD;
            }
        }

        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[n][i] *= fact[n - 1][Nsq - 1];
                fact[n][i] %= MOD;
            }
        }

        int[] inv = new int[N];
        for (int i = 0; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2);
            if (i > 0) {
                inv[i] = (inv[i] + inv[i - 1]) % MOD;
            }
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            int temp = inv[i] + inv[N - 1 - i] - 1;
            ans += A[i] * temp % MOD;
        }
        ans %= MOD;
        ans *= fact[N / Nsq][N % Nsq];
        ans %= MOD;

        System.out.println(ans);
    }

    static int pow(int a, int b) {
        if (b == 0) {
            return 1;
        }
        if (b % 2 == 0) {
            long temp = pow(a, b / 2);
            return (int) ((temp * temp) % MOD);
        } else {
            return (int) (((long) a * pow(a, b - 1)) % MOD);
        }
    }
}
// End of Code.
