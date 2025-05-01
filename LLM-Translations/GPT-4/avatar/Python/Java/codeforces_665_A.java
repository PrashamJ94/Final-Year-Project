import java.util.Scanner;

public class codeforces_665_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, at, b, bt, t1, t2, st, fin, now, ans;
        
        a = sc.nextInt();
        at = sc.nextInt();
        b = sc.nextInt();
        bt = sc.nextInt();
        t1 = sc.nextInt();
        t2 = sc.nextInt();
        
        sc.close();
        
        st = t2 + (t1 - 5) * 60;
        fin = st + at;
        now = 0;
        ans = 0;
        
        while (now < fin && now < 1140) {
            if (now + bt > st) {
                ans += 1;
            }
            now += b;
        }
        
        System.out.println(ans);
    }
}
// End of Code.
