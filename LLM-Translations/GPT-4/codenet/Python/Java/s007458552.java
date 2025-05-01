//java
import java.util.HashMap;
import java.util.Scanner;

public class s007458552 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String S = scanner.nextLine();
        HashMap<Character, Integer> C = new HashMap<>();

        for (char c : S.toCharArray()) {
            C.put(c, C.getOrDefault(c, 0) + 1);
        }

        System.out.println(C.getOrDefault('R', 0) > n - C.getOrDefault('R', 0) ? "Yes" : "No");
    }
}

// 
