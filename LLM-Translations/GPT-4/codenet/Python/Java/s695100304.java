import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class s695100304 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> x = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            x.add(scanner.nextInt());
        }
        Collections.reverse(x);
        for (int num : x) {
            System.out.print(num + " ");
        }
    }
}
// 
