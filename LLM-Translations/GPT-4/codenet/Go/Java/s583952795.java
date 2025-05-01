
import java.util.Scanner;

public class s583952795 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String s = tenToN(N, K);
        System.out.println(s.length());
    }

    public static String tenToN(int number, int n) {
        StringBuilder s = new StringBuilder();
        int tmp = number;
        while (true) {
            s.insert(0, tmp % n);
            if (tmp < n) {
                break;
            }
            tmp /= n;
        }
        return s.toString();
    }
}


