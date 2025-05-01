import java.util.Scanner;

public class s557795702 {
    private static final int MAXN = 200010;
    private static final int INF = 0x3f3f3f3f;
    private static int[] a = new int[MAXN];
    private static int[] L = new int[MAXN / 2];
    private static int[] R = new int[MAXN / 2];
    private static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
        }
        long ans = mergesort(0, n);
        System.out.println(ans);
        sc.close();
    }

    private static long merge(int left, int mid, int right) {
        int i, j, k;
        long cnt = 0;
        int n1 = mid - left;
        int n2 = right - mid;
        for (i = 0; i < n1; ++i) {
            L[i] = a[left + i];
        }
        for (i = 0; i < n2; ++i) {
            R[i] = a[mid + i];
        }
        L[n1] = R[n2] = INF;
        i = j = 0;
        for (k = left; k < right; ++k) {
            if (L[i] <= R[j]) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
                cnt += n1 - i;
            }
        }
        return cnt;
    }

    private static long mergesort(int left, int right) {
        int mid;
        long v1, v2, v3;
        if (left + 1 < right) {
            mid = (left + right) / 2;
            v1 = mergesort(left, mid);
            v2 = mergesort(mid, right);
            v3 = merge(left, mid, right);
            return v1 + v2 + v3;
        }
        return 0;
    }
}
// 
