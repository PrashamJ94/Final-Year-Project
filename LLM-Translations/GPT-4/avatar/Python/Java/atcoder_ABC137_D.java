import java.util.*;

public class atcoder_ABC137_D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        PriorityQueue<int[]> x = new PriorityQueue<>((a, b) -> b[0] - a[0] != 0 ? b[0] - a[0] : b[1] - a[1]);
        PriorityQueue<Integer> y = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            x.offer(new int[]{-day, -salary});
        }
        while (!x.isEmpty()) {
            int[] current = x.poll();
            int d = -current[0];
            int s = -current[1];
            int r = m - y.size();
            if (r >= d) {
                y.offer(s);
            } else {
                y.offer(s);
                y.poll();
            }
        }
        int sum = 0;
        while (!y.isEmpty()) {
            sum += y.poll();
        }
        System.out.println(sum);
    }
}


// End of Code.
