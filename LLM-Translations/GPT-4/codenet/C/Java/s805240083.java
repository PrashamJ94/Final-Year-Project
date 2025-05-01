
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Process {
    String name;
    int time;

    public Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class s805240083 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        Queue<Process> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            String name = sc.next();
            int time = sc.nextInt();
            queue.add(new Process(name, time));
        }

        int T = 0;
        while (!queue.isEmpty()) {
            Process p = queue.poll();
            if (p.time > q) {
                p.time -= q;
                T += q;
                queue.add(p);
            } else {
                T += p.time;
                System.out.println(p.name + " " + T);
            }
        }
    }
}

// 
