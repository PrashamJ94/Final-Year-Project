
import java.util.Arrays;
import java.util.Scanner;

public class codeforces_108_B {

    public static void main(String[] args) {
        System.out.println(s());
    }

    public static String s() {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        int[] a = Arrays.stream(scanner.nextLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        Arrays.sort(a);
        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                return "YES";
            }
        }
        return "NO";
    }
}

// End of Code
