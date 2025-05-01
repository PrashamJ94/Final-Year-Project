import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
    static class Edge {
        long p;
        int i;
        String s;

        Edge(String s, long p, int i) {
            this.s = s;
            this.p = p;
            this.i = i;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Edge[] data = new Edge[n];

        for (int i = 0; i < n; i++) {
            String s = sc.next();
            long p = sc.nextLong();
            data[i] = new Edge(s, p, i);
        }

        Arrays.sort(data, new Comparator<Edge>() {
            @Override
            public int compare(Edge e1, Edge e2) {
                int sCompare = e1.s.compareTo(e2.s);
                if (sCompare != 0) return sCompare;
                if (e1.p < e2.p) return 1;
                return -1;
            }
        });

        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }
    }
}
// 
