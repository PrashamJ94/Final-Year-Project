
import java.util.HashMap;
import java.util.Scanner;

public class atcoder_ABC105_D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        scanner.close();

        long[] cum_remainders = new long[N + 1];
        cum_remainders[0] = 0;

        for (int i = 0; i < N; i++) {
            cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
        }

        HashMap<Long, Integer> remainder_counts = new HashMap<>();
        for (long remainder : cum_remainders) {
            remainder_counts.put(remainder, remainder_counts.getOrDefault(remainder, 0) + 1);
        }

        long combinations = 0;
        for (int count : remainder_counts.values()) {
            combinations += (long) count * (count - 1) / 2;
        }

        System.out.println(combinations);
    }
}

// End of Code
