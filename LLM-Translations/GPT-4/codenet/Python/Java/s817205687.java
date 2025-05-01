import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.List;
import java.util.stream.IntStream;

public class s817205687 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = IntStream.range(0, N).map(i -> sc.nextInt() / 2).toArray();
        sc.close();

        Integer count_div_2 = null;
        for (int a : A) {
            int cnt = 0;
            while (a % 2 == 0) {
                a /= 2;
                cnt++;
            }
            if (count_div_2 == null) {
                count_div_2 = cnt;
            } else if (cnt != count_div_2) {
                System.out.println(0);
                return;
            }
        }

        int my_lcm = lcm_list(Arrays.stream(A).boxed().collect(Collectors.toList()));
        if (my_lcm > M) {
            System.out.println(0);
            return;
        }

        int tmp = M / my_lcm;
        int ans = (tmp + 1) / 2;
        System.out.println(ans);
    }

    private static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }
    }

    private static int lcm(int x, int y) {
        return (x * y) / gcd(x, y);
    }

    private static int lcm_list(List<Integer> numbers) {
        return numbers.stream().reduce(1, (a, b) -> lcm(a, b));
    }
}
// 
