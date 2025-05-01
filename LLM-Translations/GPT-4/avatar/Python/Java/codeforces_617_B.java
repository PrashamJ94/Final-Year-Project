
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class codeforces_617_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        String a = scanner.nextLine();

        if (!a.contains("1")) {
            System.out.println(0);
        } else {
            String[] splitA = a.strip().split("1");
            List<Integer> numZeros = new ArrayList<>();
            for (String s : splitA) {
                numZeros.add(s.length() + 1);
            }
            System.out.println(product(numZeros));
        }
    }

    public static int product(List<Integer> numbers) {
        int result = 1;
        for (int number : numbers) {
            result *= number;
        }
        return result;
    }
}

End of Code
