//java
import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class s878873709 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        Set<Integer> s = new HashSet<>();
        s.add(1);
        s.add(2);
        s.add(4);
        s.add(8);
        s.add(16);
        s.add(32);
        s.add(64);
        int ans = 0;

        for (int i = 1; i <= N; i++) {
            if (s.contains(i)) {
                ans = i;
            }
        }

        System.out.println(ans);
    }
}

// 
