import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class s668439281 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        ArrayList<String> ls = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ls.add(scanner.nextLine());
        }
        HashMap<String, Integer> c = new HashMap<>();
        for (String s : ls) {
            c.put(s, c.getOrDefault(s, 0) + 1);
        }

        int count = Collections.max(c.values());
        ArrayList<String> ans = new ArrayList<>();
        for (String key : c.keySet()) {
            if (c.get(key) == count) {
                ans.add(key);
            }
        }
        Collections.sort(ans);
        for (String i : ans) {
            System.out.println(i);
        }
    }
}
// 
