import java.util.Arrays;
import java.util.Scanner;

public class s171933389 {
    static final int NUM_MAX = 1000;
    static final int NUM2_MAX = NUM_MAX * NUM_MAX;
    static final int RANK_MAX = 3000;
    static final long VAL_MAX = (long) 1e+10;
    static final long SUM_MAX = VAL_MAX * 3;

    static class Range {
        int start;
        int end;
    }

    static int lowerBound(long[] arr, Range r, long key) {
        int low = r.start;
        int high = r.end;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < key) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x, y, z, rank;
        x = sc.nextInt();
        y = sc.nextInt();
        z = sc.nextInt();
        rank = sc.nextInt();

        long[] xrr = new long[x];
        long[] yrr = new long[y];
        long[] zrr = new long[z];

        for (int i = 0; i < x; i++) xrr[i] = sc.nextLong();
        for (int i = 0; i < y; i++) yrr[i] = sc.nextLong();
        for (int i = 0; i < z; i++) zrr[i] = sc.nextLong();

        long min_sum = VAL_MAX + 1;
        long max_sum = 0;
        for (int i = 0; i < z; i++) min_sum = Math.min(min_sum, zrr[i]);
        for (int i = 0; i < z; i++) max_sum = Math.max(max_sum, zrr[i]);

        long[] pair = new long[NUM2_MAX];
        int idx = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }
        Arrays.sort(pair, 0, idx);

        min_sum += pair[0];
        max_sum += pair[idx - 1];

        int[] cache = new int[NUM_MAX];
        int[] cnt_map = new int[NUM_MAX];
        long[] ans = new long[RANK_MAX];

        int size = x * y * z;
        long prev = min_sum;
        for (int r = rank; r >= 1; r--) {
            long low = prev - 1;
            long high = max_sum + 1;
            while (low + 1 < high) {
                long mid = (low + high) / 2;
                int cnt = 0;
                for (int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    Range range = new Range();
                    range.start = cache[i] - 1;
                    range.end = idx;
                    int tmp = lowerBound(pair, range, mid - pivot);
                    cnt_map[i] = tmp;
                    cnt += tmp;
                }
                if (cnt <= size - r) {
                    System.arraycopy(cnt_map, 0, cache, 0, z);
                    low = mid;
                } else {
                    high = mid;
                }
            }
            ans[r - 1] = low;
            if (low == max_sum) break;
            prev = low;
        }
        for (int i = 0; i < rank; i++) {
            System.out.println((ans[i] == 0) ? max_sum : ans[i]);
        }
    }
}
// 
