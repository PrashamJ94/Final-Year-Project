
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s851255999 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Work[] works = new Work[n];
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            works[i] = new Work(a, b);
        }
        scanner.close();

        Arrays.sort(works, Comparator.comparingInt(w -> w.limit));

        long sum = 0;
        for (Work w : works) {
            sum += w.time;
            if (sum > w.limit) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }

    static class Work {
        int time;
        int limit;

        Work(int time, int limit) {
            this.time = time;
            this.limit = limit;
        }
    }
}

// 
