import java.util.Scanner;

public class s764169243 {
    static class SegmentTree {
        int size;
        int defaultVal;
        int[] seg;

        public SegmentTree(int size, int defaultVal) {
            this.size = 1 << Integer.toBinaryString(size - 1).length();
            this.defaultVal = defaultVal;
            this.seg = new int[2 * this.size - 1];
        }

        public int segfunc(int x, int y) {
            return Math.max(x, y);
        }

        public void update(int k, int x) {
            k += this.size - 1;
            this.seg[k] = x;
            while (k > 0) {
                k = (k - 1) / 2;
                this.seg[k] = segfunc(this.seg[2 * k + 1], this.seg[2 * k + 2]);
            }
        }

        public int query(int p, int q) {
            if (q <= p) {
                return this.defaultVal;
            }
            p += this.size - 1;
            q += this.size - 2;
            int ret = this.defaultVal;
            while (q - p > 1) {
                if ((p & 1) == 0) {
                    ret = segfunc(ret, this.seg[p]);
                }
                if ((q & 1) == 1) {
                    ret = segfunc(ret, this.seg[q]);
                    q -= 1;
                }
                p = p / 2;
                q = (q - 1) / 2;
            }
            ret = segfunc(segfunc(ret, this.seg[p]), this.seg[q]);
            return ret;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        int[] ans = new int[N];
        for (int i = 0; i < N; i++) {
            ans[i] = i + 1;
        }
        SegmentTree left_seg = new SegmentTree(N, 0);
        for (int i = 0; i < N; i++) {
            int num = a[i];
            ans[num - 1] *= i + 1 - left_seg.query(0, num);
            left_seg.update(num - 1, i + 1);
        }
        SegmentTree right_seg = new SegmentTree(N, 0);
        for (int i = 0; i < N; i++) {
            int num = a[N - 1 - i];
            ans[num - 1] *= i + 1 - right_seg.query(0, num);
            right_seg.update(num - 1, i + 1);
        }

        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += ans[i];
        }
        System.out.println(sum);
    }
}
// 
