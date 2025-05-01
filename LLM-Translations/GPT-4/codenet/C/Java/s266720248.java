
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

public class s266720248 {
    private static int n, q;
    private static Queue<Process> queue = new LinkedList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        q = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Process(name, time));
        }

        int elapsedTime = 0;

        while (!queue.isEmpty()) {
            Process current = queue.poll();
            int minTime = Math.min(q, current.time);
            current.time -= minTime;
            elapsedTime += minTime;

            if (current.time > 0) {
                queue.add(current);
            } else {
                System.out.println(current.name + " " + elapsedTime);
            }
        }
    }
}


