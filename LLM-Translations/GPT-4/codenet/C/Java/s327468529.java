import java.util.Scanner;

public class s327468529 {

    static final long FOD = 998244353;

    static long[] cnt = new long[3];
    static long pcnt;
    static long[][] x = new long[3005][3005];

    static long solve() {
        long n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();

        sc.nextLine();
        String s = sc.nextLine();

        long result = 1;
        for (int i = 0; i < n * 3; i++) {
            long v;
            switch (s.charAt(i)) {
                case 'R':
                    v = 0;
                    break;
                case 'G':
                    v = 1;
                    break;
                case 'B':
                    v = 2;
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + s.charAt(i));
            }

            if (cnt[(int) ((v + 1) % 3)] != 0 && cnt[(int) ((v + 2) % 3)] != 0) {
                result *= pcnt;
                pcnt--;
                result %= FOD;
                cnt[(int) ((v + 1) % 3)]--;
                cnt[(int) ((v + 2) % 3)]--;
            } else {
                if ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) > cnt[(int) (v)]) {
                    result *= (cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) - cnt[(int) (v)];
                    result %= FOD;
                    pcnt++;
                }
                cnt[(int) (v)]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            result = (result * i) % FOD;
        }

        System.out.println(result);
        return 0;
    }

    public static void main(String[] args) {
        solve();
    }
}

// 
