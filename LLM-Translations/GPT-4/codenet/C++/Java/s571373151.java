import java.util.Scanner;
import java.util.ArrayList;

public class s571373151 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        ArrayList<Integer> foods = new ArrayList<>(m);

        for (int i = 0; i < m; i++) {
            foods.add(0);
        }

        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();

            for (int j = 0; j < k; j++) {
                int temp = scanner.nextInt();
                temp--;

                foods.set(temp, foods.get(temp) + 1);
            }
        }

        int ans = 0;
        for (int elem : foods) {
            if (elem == n) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}
// 
