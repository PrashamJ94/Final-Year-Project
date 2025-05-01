
import java.util.Scanner;

public class s509329039 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        int[] s = new int[m];
        int[] c = new int[m];

        for (int i = 0; i < m; i++) {
            s[i] = sc.nextInt();
            c[i] = sc.nextInt();
            s[i]--;
        }

        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i);
            if (st.length() != n) {
                continue;
            }

            int f = 1;
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == c[j] + '0') {

                } else {
                    f = 0;
                }
            }

            if (f == 1) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
}

// 
