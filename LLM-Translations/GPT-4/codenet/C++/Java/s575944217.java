import java.util.Scanner;
import java.util.Vector;

public class s575944217 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Vector<Integer> ans = new Vector<Integer>(n);
        for (int i = 0; i < n; i++) {
            ans.add(0);
        }
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt();
            a--;
            ans.set(a, ans.get(a) + 1);
        }
        for (int i = 0; i < n; i++) {
            System.out.println(ans.get(i));
        }
        sc.close();
    }
}
// 
