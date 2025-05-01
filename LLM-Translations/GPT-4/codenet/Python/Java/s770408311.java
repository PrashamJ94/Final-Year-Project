import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class s770408311 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<String> res = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String a = scanner.next();
            res.add(a);
        }
        System.out.println(res.size());
    }
}
// 
