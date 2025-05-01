import java.util.ArrayList;
import java.util.Scanner;

public class codeforces_474_B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> L = new ArrayList<>();
        scanner.nextLine();
        int r = 1;
        for (String k : scanner.nextLine().split(" ")) {
            for (int i = 0; i < Integer.parseInt(k); i++) {
                L.add(r);
            }
            r++;
        }
        scanner.nextLine();
        for (String j : scanner.nextLine().split(" ")) {
            System.out.println(L.get(Integer.parseInt(j) - 1));
        }
    }
}
// End of Code
