import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Task {
    String name;
    int time;

    public Task(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class s525470559 {
    public static void main(String[] args) {
        int n, q;
        int elaps = 0;
        Queue<Task> Q = new LinkedList<>();

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        q = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String name = sc.next();
            int time = sc.nextInt();
            Task tmp = new Task(name, time);
            Q.add(tmp);
        }

        while (!Q.isEmpty()) {
            Task p = Q.poll();
            if (p.time <= q) {
                elaps += p.time;
                System.out.println(p.name + " " + elaps);
            } else {
                p.time -= q;
                elaps += q;
                Q.add(p);
            }
        }
    }
}
// 
