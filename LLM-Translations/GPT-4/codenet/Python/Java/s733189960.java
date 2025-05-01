import java.util.HashMap;
import java.util.Scanner;

public class s733189960 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        HashMap<String, Integer> sdic = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char[] s = scanner.next().toCharArray();
            Arrays.sort(s);
            String sortedS = new String(s);
            if (sdic.containsKey(sortedS)) {
                sdic.put(sortedS, sdic.get(sortedS) + 1);
            } else {
                sdic.put(sortedS, 1);
            }
        }
        long ans = 0;
        for (int v : sdic.values()) {
            ans += (long) v * (v - 1) / 2;
        }
        System.out.println(ans);
    }
}
// 
