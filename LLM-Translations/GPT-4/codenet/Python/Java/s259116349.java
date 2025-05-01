import java.util.*;

public class s259116349 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
        int[][] divs = new int[100][primes.length];
        
        for (int i = 1; i <= 100; i++) {
            for (int j = 0; j < primes.length; j++) {
                int p = primes[j];
                int tmp = 0;
                while (i % p == 0) {
                    i /= p;
                    tmp++;
                }
                divs[i - 1][j] = tmp;
            }
        }
        
        int[] divsum = new int[primes.length];
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < primes.length; j++) {
                divsum[j] += divs[i - 1][j];
            }
        }
        
        int ans = 0;

        // >=74
        ans += num(75, divsum);

        // >=14 & 13~4
        ans += num(15, divsum) * (num(5, divsum) - 1);

        // >=24 & 23~2
        ans += num(25, divsum) * (num(3, divsum) - 1);

        // >=4,>=4 & >=2
        ans += num(5, divsum) * (num(5, divsum) - 1) * (num(3, divsum) - 2) / 2;
        
        System.out.println(ans);
    }

    public static int num(int n, int[] divsum) {
        int count = 0;
        for (int j : divsum) {
            if (j >= n - 1) {
                count++;
            }
        }
        return count;
    }
}
// 
