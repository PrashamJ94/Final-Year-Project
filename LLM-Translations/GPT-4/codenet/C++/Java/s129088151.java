import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s129088151 {
    public static void main(String[] args) {
        int n;
        String str, com;
        Map<String, Boolean> T = new HashMap<>();

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            com = sc.next();
            str = sc.next();
            if (com.charAt(0) == 'i') {
                T.put(str, true);
            } else {
                if (T.getOrDefault(str, false)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }
        sc.close();
    }
}
// 
