
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s480530100 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        FenwickTree fw = new FenwickTree(n);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            fw.add(i, a);
        }

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            if (t == 0) {
                int p = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                fw.add(p, x);
            } else {
                int l = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                System.out.println(fw.sum(l, r));
            }
        }
    }

    // ** copy from here to your source code **
    //
    // fenwick tree
    //  1. go lang have no generics, so implement int(long long)
    //  data type only.
    //  2. do not care overflow
    //

    // BIT :
    static class FenwickTree {
        int n;
        int[] data;

        public FenwickTree(int n) {
            this.n = n;
            this.data = new int[n];
        }

        public void add(int p, int x) {
            p++;
            while (p <= n) {
                data[p - 1] += x;
                p += p & -p;
            }
        }

        public int sum(int l, int r) {
            return sum(r) - sum(l);
        }

        private int sum(int r) {
            int s = 0;
            while (r > 0) {
                s += data[r - 1];
                r -= r & -r;
            }
            return s;
        }
    }
}


