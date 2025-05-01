
import java.io.*;
import java.util.*;

public class s819591647 {
    static final int constMod = (int) 1e9 + 7;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        solve(n, m, a);
    }

    public static void solve(int n, int m, int[] a) {
        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        int count = 0;
        for (int v : a) {
            double rate = (double) sum / (double) (4 * m);
            if ((double) v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}


