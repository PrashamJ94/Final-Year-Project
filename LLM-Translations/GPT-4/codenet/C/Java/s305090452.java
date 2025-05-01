
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class IndexVal {
    int index;
    int val;

    public IndexVal(int index, int val) {
        this.index = index;
        this.val = val;
    }
}

class Edge {
    int a, b;
    long c;

    public Edge(int a, int b, long c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

public class s305090452 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int[] a = new int[n];
        IndexVal[] p = new IndexVal[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            p[i] = new IndexVal(i, a[i]);
        }

        PriorityQueue<IndexVal> pq = new PriorityQueue<>(Comparator.comparingInt((IndexVal iv) -> iv.val).reversed());
        for (IndexVal indexVal : p) {
            pq.add(indexVal);
        }

        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = a[i] + (n - 1 - i) * d;
            r[i] = a[i] + i * d;
        }

        PriorityQueue<Edge> heap = new PriorityQueue<>(Comparator.comparingLong(e -> e.c));

        for (int i = 0; i < n; i++) {
            IndexVal indexVal = pq.poll();
            int v = indexVal.index;
            if (v > 0) {
                int minL = Integer.MAX_VALUE;
                int minIndexL = n;
                for (int j = 0; j < v; j++) {
                    if (l[j] < minL) {
                        minL = l[j];
                        minIndexL = j;
                    }
                }
                heap.add(new Edge(v, minIndexL, (long) indexVal.val + minL - (long) (n - 1 - v) * d));
            }
            if (v + 1 < n) {
                int minR = Integer.MAX_VALUE;
                int minIndexR = n;
                for (int j = v + 1; j < n; j++) {
                    if (r[j] < minR) {
                        minR = r[j];
                        minIndexR = j;
                    }
                }
                heap.add(new Edge(v, minIndexR, (long) indexVal.val + minR - (long) v * d));
            }
            l[v] = Integer.MAX_VALUE;
            r[v] = Integer.MAX_VALUE;
        }

        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
        }

        long sum = 0;
        while (-parent[0] < n) {
            Edge e = heap.poll();
            int rootA = findRoot(parent, e.a);
            int rootB = findRoot(parent, e.b);
            if (rootA == rootB) continue;
            parent[rootA] += parent[rootB];
            parent[rootB] = rootA;
            sum += e.c;
        }
        System.out.println(sum);
    }

    private static int findRoot(int[] parent, int x) {
        while (parent[x] >= 0) {
            x = parent[x];
        }
        return x;
    }
}

// 
