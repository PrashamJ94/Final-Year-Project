import java.util.Scanner;

public class s660035552 {
    static int[] low = new int[200000];
    static int[] high = new int[200000];
    static int[] a = new int[200000];
    static int[] b = new int[200000];

    public static int part(int[] a, int[] b, int l, int r) {
        int i, j, x, t;

        i = l - 1;
        j = r;

        x = b[r];

        while (true) {
            while (b[++i] < x) ;
            while (i < --j && x < b[j]) ;

            if (i >= j) break;

            t = a[i];
            a[i] = a[j];
            a[j] = t;
            t = b[i];
            b[i] = b[j];
            b[j] = t;
        }

        t = a[i];
        a[i] = a[r];
        a[r] = t;
        t = b[i];
        b[i] = b[r];
        b[r] = t;
        return i;
    }

    public static void quicksort(int[] a, int[] b, int n) {
        int l, r, v;
        int sp;

        low[0] = 0;
        high[0] = n - 1;
        sp = 1;

        while (sp > 0) {
            sp--;
            l = low[sp];
            r = high[sp];

            if (l >= r) ;

            else {
                v = part(a, b, l, r);

                if (v - l < r - v) {
                    low[sp] = v + 1;
                    high[sp++] = r;
                    low[sp] = l;
                    high[sp++] = v - 1;
                } else {
                    low[sp] = l;
                    high[sp++] = v - 1;
                    low[sp] = v + 1;
                    high[sp++] = r;
                }
            }
        }
    }

    public static void main(String[] args) {
        int n, m;
        int i;
        int[] a = new int[100006];
        int[] b = new int[100006];
        int cnt = 0;
        int t;

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        for (i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }

        quicksort(a, b, m);

        t = 0;
        for (i = 0; i < m; i++) {
            if (t <= a[i]) {
                t = b[i];
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}
// 
