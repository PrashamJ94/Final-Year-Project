import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class codeforces_351_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        List<Double> arr = new ArrayList<>();
        for (String s : sc.nextLine().split(" ")) {
            arr.add(Double.parseDouble(s));
        }
        arr.sort((x, y) -> Double.compare(x - (int) x.doubleValue(), y - (int) y.doubleValue()));
        arr.removeIf(x -> x - (int) x.doubleValue() == 0);
        int o = 2 * n - arr.size();
        double arrSum = arr.stream().mapToDouble(x -> x - (int) x.doubleValue()).sum();
        double res = (int) 2e9;
        for (int i = 0; i < n + 1; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }
        System.out.printf("%.3f%n", res);
    }
}
// End of Code
