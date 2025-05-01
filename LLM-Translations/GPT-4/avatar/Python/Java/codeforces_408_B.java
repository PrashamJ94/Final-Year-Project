import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class codeforces_408_B {
    public static void main(String[] args) {
        int t = 1;
        for (int i = 0; i < t; i++) {
            solution();
        }
    }

    public static void solution() {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        Map<Character, Integer> boughtCount = countCharacters(line);
        line = sc.nextLine();
        Map<Character, Integer> madeCount = countCharacters(line);

        int res = 0;
        for (char color : madeCount.keySet()) {
            if (!boughtCount.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }
        System.out.println(res);
    }

    public static Map<Character, Integer> countCharacters(String line) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c : line.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }
        return count;
    }
}
// End of Code.
