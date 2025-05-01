import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class s269975433 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Q = sc.nextInt();

        List<List<Integer>> Q_groups = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            List<Integer> group = new ArrayList<>();
            for (int j = 0; j < 4; j++) {
                group.add(sc.nextInt());
            }
            Q_groups.add(group);
        }

        int max_score = findMaxScore(N, M, Q_groups);
        System.out.println(max_score);
    }

    private static int findMaxScore(int N, int M, List<List<Integer>> Q_groups) {
        List<List<Integer>> combinations = generateCombinations(N, M);
        int max_score = 0;

        for (List<Integer> p : combinations) {
            int temp_score = 0;
            for (List<Integer> q : Q_groups) {
                if (p.get(q.get(1) - 1) - p.get(q.get(0) - 1) == q.get(2)) {
                    temp_score += q.get(3);
                }
            }
            max_score = Math.max(max_score, temp_score);
        }

        return max_score;
    }

    private static List<List<Integer>> generateCombinations(int N, int M) {
        return IntStream.rangeClosed(1, M)
                .boxed()
                .flatMap(a -> combinationsWithRepeat(N - 1, M, a)
                        .stream()
                        .map(list -> {
                            list.add(0, a);
                            return list;
                        }))
                .collect(Collectors.toList());
    }

    private static List<List<Integer>> combinationsWithRepeat(int N, int M, int start) {
        if (N == 1) {
            return IntStream.rangeClosed(start, M)
                    .mapToObj(a -> {
                        List<Integer> list = new ArrayList<>();
                        list.add(a);
                        return list;
                    })
                    .collect(Collectors.toList());
        } else {
            return IntStream.rangeClosed(start, M)
                    .boxed()
                    .flatMap(a -> combinationsWithRepeat(N - 1, M, a)
                            .stream()
                            .map(list -> {
                                list.add(0, a);
                                return list;
                            }))
                    .collect(Collectors.toList());
        }
    }
}
// 
