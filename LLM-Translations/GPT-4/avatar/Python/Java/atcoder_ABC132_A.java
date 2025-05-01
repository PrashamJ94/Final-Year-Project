import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class atcoder_ABC132_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        HashMap<Character, Integer> c = new HashMap<>();
        for (char ch : S.toCharArray()) {
            c.put(ch, c.getOrDefault(ch, 0) + 1);
        }
        Set<Character> Sa = new HashSet<>(c.keySet());
        if (Sa.size() != 2) {
            System.out.println("No");
        } else {
            boolean flag = true;
            for (Character i : Sa) {
                if (c.get(i) != 2) {
                    System.out.println("No");
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println("Yes");
            }
        }
    }
}
// End of Code
