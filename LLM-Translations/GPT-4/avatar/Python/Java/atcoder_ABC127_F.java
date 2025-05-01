import java.util.*;

public class atcoder_ABC127_F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        long sum_b = 0, sum_p1 = 0, sum_p2 = 0;
        PriorityQueue<Long> p1 = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Long> p2 = new PriorityQueue<>();

        for (int i = 0; i < q; i++) {
            int type = sc.nextInt();

            if (type == 2) {
                if (p1.size() == p2.size()) {
                    System.out.println(p2.peek() + " " + (sum_p1 - p1.size() * p2.peek() + p2.size() * p2.peek() - sum_p2 + sum_b));
                } else {
                    System.out.println(p1.peek() + " " + (sum_p1 - p1.size() * p1.peek() + p2.size() * p1.peek() - sum_p2 + sum_b));
                }
            } else {
                long x = sc.nextLong();
                long a = sc.nextLong();
                sum_b += a;

                if (p1.isEmpty() || p1.peek() <= x) {
                    p1.add(x);
                    sum_p1 += x;
                } else {
                    p2.add(x);
                    sum_p2 += x;
                }

                if (p1.size() < p2.size()) {
                    long k = p2.poll();
                    p1.add(k);
                    sum_p2 -= k;
                    sum_p1 += k;
                }

                if (p1.size() - 1 > p2.size()) {
                    long k = p1.poll();
                    p2.add(k);
                    sum_p1 -= k;
                    sum_p2 += k;
                }
            }
        }
    }
}

// End of Code
