import java.util.*;
import java.io.*;

public class s134430594 {
    static long[] a, dl;
    static int n;
    static Ban[] bans;
    static long ans = 0;

    static class Ban {
        int l, r;
        long val;

        Ban() {}

        Ban(int l_, int r_, long val_) {
            l = l_;
            r = r_;
            val = val_;
        }
    }

    static class Sp {
        static final int LIM = 20; 
        static final int N = (int) 2e5 + 7;

        static long[][] mn = new long[LIM][N];
        static int[] pw = new int[N];

        static void init(long[] a) {
            int n = a.length;
            for (int i = 0; i < n; i++) {
                mn[0][i] = a[i]; 
            }
            for (int i = 0; i + 1 < LIM; i++) {
                for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                    mn[i + 1][j] = Math.max(mn[i][j], mn[i][j + (1 << i)]);
                }
            }
            pw[1] = 0;
            for (int i = 2; i < N; i++) {
                pw[i] = pw[i / 2] + 1;
            }
        } 

        static long get(int l, int r) {
            r++;
            int p = pw[r - l];
            return Math.min(mn[p][l], mn[p][r - (1 << p)]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new long[n];
        dl = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > i) {
                System.out.println(-1);
                return;
            }
            dl[i] = i - a[i];
        }
        List<Ban> banList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = i;
            while (r + 1 < n && a[r] + 1 == a[r + 1]) {
                r++;
            }
            ans += a[r];
            i = r;
            banList.add(new Ban(r - (int) a[r], r, r - a[r]));
        }
        bans = banList.toArray(new Ban[0]);
        Sp.init(dl);
        for (Ban t : bans) {
            if (Sp.get(t.l, t.r) > t.val) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);
    }
}
// 
