
public class s846328722 {
    public static void main(String[] args) {
        int i, n, q, t, count = 0;
        int[] s = new int[100000];
        java.util.Scanner sc = new java.util.Scanner(System.in);

        n = sc.nextInt();

        for (i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }

        q = sc.nextInt();

        for (i = 0; i < q; i++) {
            t = sc.nextInt();
            if (linearSearch(s, n, t)) count++;
        }
        System.out.println(count);
    }

    public static boolean linearSearch(int[] a, int n, int key) {
        int i = 0;

        while (i < n && a[i] != key) {
            i++;
        }
        return i != n;
    }
}

// 
