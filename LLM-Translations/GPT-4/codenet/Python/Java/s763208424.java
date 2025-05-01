import java.util.PriorityQueue;

public class s763208424 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        PriorityQueue<Integer> a = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        for (int i = 0; i < m; i++) {
            int x = a.poll();
            a.add(x / 2);
        }

        int sum = 0;
        for (int val : a) {
            sum += val;
        }
        System.out.println(sum);
    }

    private static int dis(int x, int y) {
        return x / (int) Math.pow(2, y);
    }
}
// 
