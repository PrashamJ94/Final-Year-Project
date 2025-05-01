import java.util.Scanner;

public class s484809551 {

    public static int N_MAX = 100;
    public static int P_MAX = 100;
    public static int DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1;

    public static int min(int a, int b) {
        return (a < b) ? a : b;
    }

    public static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    public static int abs(int a) {
        return (a < 0) ? -a : a;
    }

    public static int abss(int a, int b) {
        return (a > b) ? a - b : b - a;
    }

    public static String strrstr(String string, String pattern) {
        int offset = 0;
        String lastP = null;

        while (string.indexOf(pattern, offset) != -1 && string.charAt(offset) != '\0') {
            lastP = string.substring(string.indexOf(pattern, offset));
            offset++;
        }

        return lastP;
    }

    public static int compare_f(int a, int b) {
        return (a < b) ? -1 : 1;
    }

    public static long comb(long n, long r) {
        long result = 1;

        for (long i = 0; i < r; i++) {
            result *= n - i;
            result /= i + 1;
        }

        return result;
    }

    public static long gcd(long m, long n) {
        long temp;

        while (m % n != 0) {
            temp = n;
            n = m % n;
            m = temp;
        }

        return n;
    }

    public static void main(String[] args) {
        String patternBase = "keyence";
        String top, bottom;
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();

        int len = S.length();
        boolean found = false;

        for (int offset = 0; offset < patternBase.length(); offset++) {
            top = patternBase.substring(0, offset);
            bottom = patternBase.substring(offset);

            int topSearchIndex = S.indexOf(top);
            if (topSearchIndex != -1) {
                String bottomSearch = strrstr(S.substring(topSearchIndex + offset), bottom);
                if (bottomSearch != null) {
                    int sepCount = 0;

                    if (topSearchIndex != 0) {
                        sepCount++;
                    }
                    if (topSearchIndex + offset != S.indexOf(bottomSearch)) {
                        sepCount++;
                    }
                    if (bottomSearch.length() != S.length() - S.indexOf(bottomSearch)) {
                        sepCount++;
                    }

                    if (sepCount <= 1) {
                        found = true;
                        break;
                    }
                }
            }
        }

        System.out.println((found ? "YES" : "NO"));
    }
}
// 
