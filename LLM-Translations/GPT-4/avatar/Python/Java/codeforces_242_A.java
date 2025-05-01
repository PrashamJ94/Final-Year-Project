import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class codeforces_242_A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        List<Pair> games = new ArrayList<>();
        for (int i = a; i <= x; i++) {
            if (i <= b) {
                continue;
            } else {
                for (int j = b; j <= y; j++) {
                    if (i > j) {
                        games.add(new Pair(i, j));
                    }
                }
            }
        }

        System.out.println(games.size());
        for (Pair pair : games) {
            System.out.println(pair.first + " " + pair.second);
        }
    }

    static public class codeforces_242_A {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
// End of Code
