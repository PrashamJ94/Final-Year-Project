import java.util.Scanner;

public class atcoder_AGC037_E {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine();
        String S = scanner.nextLine();
        boolean aaaa = false;
        if (K >= 15) {
            aaaa = true;
        } else if (Math.pow(2, K) >= N) {
            aaaa = true;
        }
        if (aaaa) {
            System.out.println(S.chars().min().getAsInt() * N);
            System.exit(0);
        }

        S = getLastDict(S, N);
        if (K == 1) {
            System.out.println(S);
        } else {
            int count = 0;
            for (char c : S.toCharArray()) {
                if (c == S.charAt(0)) {
                    count++;
                } else {
                    break;
                }
            }
            if (count * (Math.pow(2, K - 1)) >= N) {
                System.out.println(String.valueOf(S.charAt(0)).repeat(N));
            } else {
                S = String.valueOf(S.charAt(0)).repeat(count * ((int) Math.pow(2, K - 1) - 1)) + S;
                System.out.println(S.substring(0, N));
            }
        }
    }

    private static String getLastDict(String s_str, int N) {
        String U = s_str + new StringBuilder(s_str).reverse().toString();
        char c = s_str.chars().min().getAsInt();
        int p = U.indexOf(c);
        int minindex = p;
        p++;
        while (p <= N) {
            if (U.charAt(p) == c) {
                if (checkNormalDict(U, minindex, p, N)) {
                    minindex = p;
                }
            }
            p++;
        }
        return U.substring(minindex, minindex + N);
    }

    private static boolean checkNormalDict(String u, int pointer1, int pointer2, int N) {
        for (int i = 0; i < N; i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }
}
// End of Code.
