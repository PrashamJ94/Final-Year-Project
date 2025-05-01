import java.util.Scanner;
import java.util.Arrays;

public class atcoder_ABC170_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] a = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();

        for (int e = 0; e < a.length; e++) {
            if (a[e] == 0) {
                System.out.println(e + 1);
                break;
            }
        }
    }
}
// End of Code
