import java.util.Scanner;

public class atcoder_AGC025_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        String[] a = {"10", "100", "1000", "10000", "100000"};
        int sum = 0;

        for (char digit : n.toCharArray()) {
            sum += Character.getNumericValue(digit);
        }

        boolean found = false;
        for (String number : a) {
            if (n.equals(number)) {
                found = true;
                break;
            }
        }

        if (found) {
            System.out.println(10);
        } else {
            System.out.println(sum);
        }
    }
}
// End of Code
