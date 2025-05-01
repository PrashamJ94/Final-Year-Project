import java.util.*;

public class s735480710 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] a = scanner.nextLine().split(" ");
        List<String> b = new ArrayList<>();

        for (int i = 1; i < a.length; i += 2) {
            b.add(a[i]);
        }
        Collections.reverse(b);
        for (int i = 0; i < a.length; i += 2) {
            b.add(a[i]);
        }
        if (a.length % 2 == 0) {
            System.out.println(String.join(" ", b));
        } else {
            Collections.reverse(b);
            System.out.println(String.join(" ", b));
        }
    }
}
// 
