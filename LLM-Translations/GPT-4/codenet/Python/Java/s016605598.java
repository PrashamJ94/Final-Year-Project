import java.util.PriorityQueue;
import java.util.Scanner;

public class s016605598 {
    public static void main(String[] args) {
        int constVal = 0;
        int cnt = 0;
        int leftSum = 0;
        int rightSum = 0;
        
        PriorityQueue<Integer> left = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<Integer> right = new PriorityQueue<>();

        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt();
            if (t == 1) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                constVal += b;
                if (cnt % 2 == 0) {
                    if (right.isEmpty()) {
                        left.offer(a);
                        leftSum += a;
                        cnt++;
                        continue;
                    }

                    int c = right.poll();
                    rightSum -= c;
                    if (a <= c) {
                        left.offer(a);
                        right.offer(c);
                        leftSum += a;
                        rightSum += c;
                    } else {
                        left.offer(c);
                        right.offer(a);
                        leftSum += c;
                        rightSum += a;
                    }
                } else {
                    int c = left.poll();
                    leftSum -= c;
                    if (a <= -c) {
                        left.offer(a);
                        right.offer(-c);
                        leftSum += a;
                        rightSum -= c;
                    } else {
                        left.offer(c);
                        right.offer(a);
                        leftSum -= c;
                        rightSum += a;
                    }
                }
                cnt++;
            } else {
                int tmp = left.peek();
                System.out.println(tmp + " " + (constVal - leftSum + rightSum + tmp * (cnt % 2)));
            }
        }
        scanner.close();
    }
}
// 
