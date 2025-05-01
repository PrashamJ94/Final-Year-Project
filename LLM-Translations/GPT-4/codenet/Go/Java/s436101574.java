import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.stream.Collectors;

public class s436101574 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String t = sc.next();

        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length() - t.length() + 1; i++) {
            boolean f = true;
            char[] ss = s.toCharArray();

            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i + j) != t.charAt(j) && s.charAt(i + j) != '?') {
                    f = false;
                    break;
                } else {
                    ss[i + j] = t.charAt(j);
                }
            }
            if (f) {
                ans.add(new String(ss).replace("?", "a"));
            }
        }
        Collections.sort(ans);
        if (ans.isEmpty()) {
            System.out.println("UNRESTORABLE");
        } else {
            System.out.println(ans.get(0));
        }
    }
}
// 
