
import java.util.Scanner;

public class s448220316 {

    static int[] fa = new int[100005];
    static int[] v = new int[200005];

    static int get(int x) {
        if (x == fa[x]) return x;
        int f = get(fa[x]);
        v[x] += v[fa[x]];
        return fa[x] = f;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 1; i <= n; i++) fa[i] = i;
        boolean flag = true;
        for (int i = 1; i <= m; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int vi = sc.nextInt();
            int li = get(l), ri = get(r);
            if (li != ri) {
                v[ri] = vi - v[r] + v[l];
                fa[ri] = li;
            } else {
                if (v[r] - v[l] != vi) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        sc.close();
    }
}

// 
