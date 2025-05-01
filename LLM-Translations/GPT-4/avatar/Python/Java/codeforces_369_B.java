
import java.util.*;

public class codeforces_369_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();
        List<Integer> ans = getNums(k, sk);
        ans.addAll(getNums(n - k, sa - sk));
        for (int num : ans) {
            System.out.print(num + " ");
        }
    }

    private static List<Integer> getNums(int num, int t) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < num; i++) {
            result.add(t / num + (i < t % num ? 1 : 0));
        }
        return result;
    }
}

// End of Code
