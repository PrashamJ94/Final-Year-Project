public class codeforces_342_B {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), s = scanner.nextInt(), f = scanner.nextInt();
        int d;
        char c;
        if (s < f) {
            d = 1;
            c = 'R';
        } else {
            d = -1;
            c = 'L';
        }
        StringBuilder res = new StringBuilder();
        int i = 1, j = s;
        int t = scanner.nextInt(), l = scanner.nextInt(), r = scanner.nextInt();
        int k = 1;
        while (j != f) {
            if (i > t && k < m) {
                t = scanner.nextInt();
                l = scanner.nextInt();
                r = scanner.nextInt();
                k += 1;
            }
            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                res.append('X');
            } else {
                res.append(c);
                j += d;
            }
            i += 1;
        }
        System.out.println(res.toString());
    }
}
// End of Code
