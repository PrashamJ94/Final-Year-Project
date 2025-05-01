import java.util.*;

public class s814403222 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while((n = sc.nextInt()) != 0) {
            int m;
            Pair[] v = new Pair[n];
            List<List<Integer>> d = new ArrayList<>();
            for (int i = 0; i < 33; i++) {
                d.add(new ArrayList<>());
            }
            for (int i = 0; i < n; i++) {
                v[i] = new Pair(0, sc.next());
                m = sc.nextInt();
                for (int j = 0; j < m; j++) {
                    int a = sc.nextInt();
                    v[i].first += n - d.get(a).size();
                    for (int k = 0; k < d.get(a).size(); k++) {
                        v[d.get(a).get(k)].first--;
                    }
                    d.get(a).add(i);
                }
            }
            Arrays.sort(v);
            System.out.println(v[0].first + " " + v[0].second);
        }
    }

    static class Pair implements Comparable<Pair> {
        int first;
        String second;

        Pair(int first, String second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair o) {
            if (this.first == o.first) {
                return this.second.compareTo(o.second);
            }
            return o.first - this.first;
        }
    }
}
// 
