import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;

public class s700281300 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String s = sc.next();

            Set<String> st = new HashSet<>();
            st.add(s);

            for (int j = 1; j < s.length(); j++) {
                StringBuilder ss = new StringBuilder();
                for (int k = 0; k < j; k++) {
                    ss.append(s.charAt(k));
                }
                String res = ss.toString();

                StringBuilder ss2 = new StringBuilder();
                for (int k = j; k < s.length(); k++) {
                    ss2.append(s.charAt(k));
                }

                String res2 = ss2.toString();

                String t = res;
                res = new StringBuilder(res).reverse().toString();
                String t2 = res2;
                res2 = new StringBuilder(res2).reverse().toString();

                Collections.addAll(st, t + t2, t2 + t, t + res2, res2 + t, res + t2, t2 + res, res + res2, res2 + res);
            }

            System.out.println(st.size());
        }
    }
}
// 
