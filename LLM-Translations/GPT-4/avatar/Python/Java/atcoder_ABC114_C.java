import java.util.HashSet;
import java.util.Set;

public class atcoder_ABC114_C {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        System.out.println(aaa("0", N));
    }

    public static int aaa(String n, int N) {
        if (Integer.parseInt(n) > N) {
            return 0;
        }
        Set<Character> set = new HashSet<>();
        for (char c : n.toCharArray()) {
            set.add(c);
        }
        int ans = (set.contains('7') && set.contains('5') && set.contains('3')) ? 1 : 0;
        for (char i : "753".toCharArray()) {
            ans += aaa(n + i, N);
        }
        return ans;
    }
}
// End of Code
