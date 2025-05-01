import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s058450440 {

    private static int[] a;
    private static int ans = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Character, Integer> dic = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0);
            switch (c) {
                case 'M':
                case 'A':
                case 'R':
                case 'C':
                case 'H':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
            }
        }

        a = new int[dic.size()];
        int index = 0;
        for (int v : dic.values()) {
            a[index++] = v;
        }

        dfs(3, 0, 1);
        System.out.println(ans);
    }

    private static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j]);
        }
    }
}
// 
