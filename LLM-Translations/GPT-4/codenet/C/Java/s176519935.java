import java.util.Scanner;
import java.util.PriorityQueue;

public class s176519935 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        PriorityQueue<Long> heap = new PriorityQueue<>((x, y) -> Long.compare(y, x));

        for (int i = 0; i < n; i++) {
            heap.add(a[i]);
        }

        for (int i = 0; i < m; i++) {
            long tm = heap.poll();
            tm /= 2;
            heap.add(tm);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += heap.poll();
        }

        System.out.println(ans);
    }
}
// 
