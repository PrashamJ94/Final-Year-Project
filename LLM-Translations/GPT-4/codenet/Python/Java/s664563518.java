import java.util.*;

public class s664563518 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String[] s = new String[N];
        int[] t = new int[N];

        for (int i = 0; i < N; i++) {
            s[i] = scanner.next();
            t[i] = scanner.nextInt();
        }

        String X = scanner.next();
        int xi = 0;

        for (int i = 0; i < N; i++) {
            if (s[i].equals(X)) {
                xi = i;
                break;
            }
        }

        int ans = 0;

        for (int i = 0; i < N; i++) {
            if (xi < i) {
                ans += t[i];
            }
        }

        System.out.println(ans);
    }
}
// 
