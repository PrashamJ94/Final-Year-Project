
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class codeforces_400_A {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        while (t-- > 0) {
            String x = reader.readLine();
            List<Integer> s = new ArrayList<>();
            for (char c : x.toCharArray()) {
                if (c == 'O') {
                    s.add(0);
                } else {
                    s.add(1);
                }
            }
            List<List<Integer>> tot = new ArrayList<>();
            for (int i = 1; i <= 12; i++) {
                if (12 % i == 0) {
                    if (help(i, 12 / i, s)) {
                        tot.add(Stream.of(12 / i, i).collect(Collectors.toList()));
                    }
                }
            }
            System.out.print(tot.size() + " ");
            for (List<Integer> a : tot) {
                System.out.print(a.get(0) + "x" + a.get(1) + " ");
            }
            System.out.println();
        }
    }

    public static boolean help(int a, int b, List<Integer> l) {
        List<List<Integer>> tot = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            tot.add(l.subList(i * a, i * a + a));
        }
        for (List<Integer> row : transpose(tot)) {
            int sum = row.stream().mapToInt(Integer::intValue).sum();
            if (sum == b) {
                return true;
            }
        }
        return false;
    }

    public static <T> List<List<T>> transpose(List<List<T>> matrix) {
        List<List<T>> transposed = new ArrayList<>();
        for (int i = 0; i < matrix.get(0).size(); i++) {
            List<T> newRow = new ArrayList<>();
            for (List<T> row : matrix) {
                newRow.add(row.get(i));
            }
            transposed.add(newRow);
        }
        return transposed;
    }
}

// End of Code
