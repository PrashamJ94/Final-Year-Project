
import java.util.Scanner;

public class s097554686 {
    static final int size = 100001;

    public static void main(String[] args) {
        int n, t;
        int l, r;
        int[] mem = new int[size];
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = sc.nextInt();
        for (int i = 0; i < n; i++) {
            l = sc.nextInt();
            r = sc.nextInt();
            mem[l] += 1;
            mem[r] -= 1;
        }
        int ans = mem[0];
        for (int i = 1; i < t + 1; i++) {
            mem[i] += mem[i - 1];
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }
        System.out.println(ans);
    }
}

// 
