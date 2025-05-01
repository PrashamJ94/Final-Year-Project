import java.util.*;

class Process {
    String name;
    int time;

    public Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class s644382798 {
    private static final int LEN = 100005;
    private static LinkedList<Process> queue = new LinkedList<>();
    private static int head, tail, n;

    public static void main(String[] args) {
        int elaps = 0, c;
        int i, q;
        Process u;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        q = sc.nextInt();

        for (i = 1; i <= n; i++) {
            String name = sc.next();
            int time = sc.nextInt();
            queue.add(new Process(name, time));
        }

        while (!queue.isEmpty()) {
            u = queue.poll();
            c = Math.min(q, u.time);
            u.time -= c;
            elaps += c;
            if (u.time > 0)
                queue.add(u);
            else
                System.out.printf("%s %d\n", u.name, elaps);
        }

        sc.close();
    }
}
// 
