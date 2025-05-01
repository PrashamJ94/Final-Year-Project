
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class atcoder_ABC174_C {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine().trim());
        BigInteger t = BigInteger.ZERO;
        for (int i = 1; i <= k; i++) {
            t = t.mod(BigInteger.valueOf(k)).multiply(BigInteger.TEN).add(BigInteger.valueOf(7));
            if (t.mod(BigInteger.valueOf(k)).equals(BigInteger.ZERO)) {
                System.out.println(i);
                break;
            }
        }
        if (!t.mod(BigInteger.valueOf(k)).equals(BigInteger.ZERO)) {
            System.out.println(-1);
        }
    }
}

// End of Code.
