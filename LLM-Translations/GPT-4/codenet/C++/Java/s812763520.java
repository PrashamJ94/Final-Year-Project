import java.util.Scanner;

public class s812763520 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, ans = 0;
        String a, b, c;
        n = sc.nextInt();
        a = sc.next();
        b = sc.next();
        c = sc.next();
        
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)) {
            } else if (a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)) {
                ans++;
            } else {
                ans += 2;
            }
        }
        System.out.println(ans);
    }
}
// 
