
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class s512742019 {

    static class Mon implements Comparable<Mon> {
        int x, h;

        public Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Mon other) {
            return this.x - other.x;
        }
    }

    static class Node {
        int x, h;

        public Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            M[i] = new Mon(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(M);
        Queue<Node> q = new LinkedList<>();
        int ans = 0;
        int total = 0;
        for (int i = 0; i < N; i++) {
            Mon m = M[i];
            while (!q.isEmpty() && q.peek().x < m.x) {
                total -= q.poll().h;
            }
            if (total < m.h) {
                m.h -= total;
                int count = (m.h + A - 1) / A;
                ans += count;
                int damage = count * A;
                q.add(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }

        pw.println(ans);
        pw.flush();
    }
}

// 
