//java
import java.io.*;
import java.util.*;
import org.jgrapht.*;
import org.jgrapht.alg.shortestpath.*;
import org.jgrapht.graph.*;

public class s749244504 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        int[][] C = new int[10][10];
        for (int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                C[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] A = new int[h][w];
        for (int i = 0; i < h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        SimpleDirectedGraph<Integer, DefaultEdge> G = new SimpleDirectedGraph<>(DefaultEdge.class);
        for (int i = 0; i < 10; i++) {
            G.addVertex(i);
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                G.addEdge(i, j, new DefaultEdge());
            }
        }

        DijkstraShortestPath<Integer, DefaultEdge> dijkstra = new DijkstraShortestPath<>(G);
        Map<Integer, Double> d = new HashMap<>();
        for (int i = 0; i < 10; i++) {
            if (i == 1) {
                continue;
            }
            d.put(i, dijkstra.getPathWeight(i, 1));
        }

        long s = 0;
        for (int[] row : A) {
            for (int a : row) {
                if (a == -1 || a == 1) {
                    continue;
                }
                s += d.get(a);
            }
        }
        System.out.println(s);
    }
}

// 
