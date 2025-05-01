import java.util.*;
import java.util.stream.Collectors;

public class atcoder_ABC128_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<List<Integer>> li = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int k = scanner.nextInt();
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                list.add(scanner.nextInt());
            }
            li.add(list);
        }
        int[] p = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = scanner.nextInt();
        }

        Set<Integer> q = li.stream().flatMap(List::stream).collect(Collectors.toSet());
        Set<Integer> r = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            r.add(i);
        }
        Set<Integer> v = new HashSet<>(r);
        v.removeAll(q);

        int ans = 0;
        for (int i = 0; i <= q.size(); i++) {
            for (Set<Integer> s : combinations(q, i)) {
                boolean valid = true;
                for (int j = 0; j < m; j++) {
                    Set<Integer> intersection = new HashSet<>(s);
                    intersection.retainAll(li.get(j));
                    if (intersection.size() % 2 != p[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans += (1 << v.size());
                }
            }
        }
        System.out.println(ans);
    }

    public static Set<Set<Integer>> combinations(Set<Integer> q, int i) {
        List<Integer> qList = new ArrayList<>(q);
        Set<Set<Integer>> result = new HashSet<>();
        combinationsHelper(qList, i, 0, new HashSet<>(), result);
        return result;
    }

    public static void combinationsHelper(List<Integer> qList, int i, int start, Set<Integer> current, Set<Set<Integer>> result) {
        if (i == 0) {
            result.add(new HashSet<>(current));
            return;
        }

        for (int j = start; j < qList.size(); j++) {
            current.add(qList.get(j));
            combinationsHelper(qList, i - 1, j + 1, current, result);
            current.remove(qList.get(j));
        }
    }
}
// End of Code.
