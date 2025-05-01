
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s129530281 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Segment seg = new Segment();
        seg.init(n);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(st.nextToken()));
        }

        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long) seg.bucket[0][i];
        }

        System.out.println(ans);
    }

    static class Segment {
        int n, h, i, chunk;
        int[] unit;
        int[][] bucket;

        void init(int n) {
            this.n = n;
            this.unit = new int[1];
            this.unit[0] = 1;
            this.bucket = new int[1][];
            this.bucket[0] = new int[n];

            int chunk = 8;
            for (int i = 0; n > 1; i++) {
                n = (n - 1) / chunk + 1;
                this.bucket = append(this.bucket, new int[n]);
                this.unit = append(this.unit, this.unit[i] * chunk);
            }
            this.h = this.unit.length;
            this.chunk = chunk;
        }

        int[] append(int[] arr, int value) {
            int[] newArr = new int[arr.length + 1];
            System.arraycopy(arr, 0, newArr, 0, arr.length);
            newArr[arr.length] = value;
            return newArr;
        }

        int[][] append(int[][] arr, int[] value) {
            int[][] newArr = new int[arr.length + 1][];
            System.arraycopy(arr, 0, newArr, 0, arr.length);
            newArr[arr.length] = value;
            return newArr;
        }

        void maximize(int index, int value) {
            this.bucket[0][index] = value;
            for (this.i = 0; this.i < this.h - 1; this.i++) {
                int s = index - index % this.chunk;
                int t = s + this.chunk;
                if (t > this.bucket[this.i].length) {
                    t = this.bucket[this.i].length;
                }
                int parent = index / this.chunk;
                int max = 0;
                for (int i = s; i < t; i++) {
                    if (max < this.bucket[this.i][i]) {
                        max = this.bucket[this.i][i];
                    }
                }
                this.bucket[this.i + 1][parent] = max;
                index /= this.chunk;
            }
        }

        int top() {
            int index = 0;
            for (this.i = this.h - 2; this.i >= 0; this.i--) {
                int s = index * this.chunk;
                int t = s + this.chunk;
                if (t > this.bucket[this.i].length) {
                    t = this.bucket[this.i].length;
                }
                for (int i = s; i < t; i++) {
                    if (this.bucket[this.i][i] == this.bucket[this.i + 1][index]) {
                        index = i;
                        break;
                    }
                }
            }

            return index;
        }
    }
}


