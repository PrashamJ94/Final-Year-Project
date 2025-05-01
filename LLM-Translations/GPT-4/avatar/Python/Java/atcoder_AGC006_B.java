import java.util.*;
import java.util.stream.*;

public class atcoder_AGC006_B {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        int X = s.nextInt();
        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            List<Integer> xs = new ArrayList<>();
            if (X == N * 2 - 2) {
                xs.addAll(IntStream.rangeClosed(N - 1, X + 2).boxed().collect(Collectors.toList()));
                xs.addAll(IntStream.rangeClosed(1, N - 1).boxed().collect(Collectors.toList()));
            } else {
                List<Integer> ys = new ArrayList<>();
                ys.addAll(IntStream.rangeClosed(1, X - 1).boxed().collect(Collectors.toList()));
                ys.addAll(IntStream.rangeClosed(X + 3, N * 2).boxed().collect(Collectors.toList()));
                xs.addAll(ys.subList(0, N - 3));
                xs.add(X + 2);
                xs.add(X - 1);
                xs.add(X);
                xs.add(X + 1);
                xs.addAll(ys.subList(N - 3, ys.size()));
            }
            for (int x : xs) {
                System.out.println(x);
            }
        }
    }
}

// End of Code
