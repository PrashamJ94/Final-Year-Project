public class s922746568 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();

        int r_cnt = countChar(s, 'R');
        int g_cnt = countChar(s, 'G');
        int b_cnt = countChar(s, 'B');

        int ans = r_cnt * g_cnt * b_cnt;

        for (int i = 0; i < n; i++) {
            for (int d = 0; d < n; d++) {
                int j = i + d;
                int k = j + d;
                if (k >= n) {
                    break;
                }
                if (s.charAt(i) != s.charAt(j) && s.charAt(j) != s.charAt(k) && s.charAt(k) != s.charAt(i)) {
                    ans -= 1;
                }
            }
        }
        System.out.println(ans);
    }

    public static int countChar(String s, char c) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                count++;
            }
        }
        return count;
    }
}
// 
