import java.util.Scanner;
import java.util.function.IntBinaryOperator;
import java.util.stream.IntStream;

public class atcoder_ABC122_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();
        int[][] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i][0] = scanner.nextInt();
            problems[i][1] = scanner.nextInt();
        }
        IntBinaryOperator count = (total, i) -> total + (s.substring(i - 1, i + 1).equals("AC") ? 1 : 0);
        int[] cumsum = IntStream.concat(IntStream.of(0), IntStream.range(1, n)).reduce(count).getAsInt();
        for (int[] problem : problems) {
            System.out.println(cumsum[problem[1] - 1] - cumsum[problem[0] - 1]);
        }
    }
}
// End of Code.
