
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class codeforces_469_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int maxLevel = sc.nextInt();
        sc.nextLine();
        String[] xLevels = sc.nextLine().split(" ");
        String[] yLevels = sc.nextLine().split(" ");
        Set<Integer> xSet = new HashSet<>();
        Set<Integer> ySet = new HashSet<>();

        for (int i = 1; i < xLevels.length; i++) {
            xSet.add(Integer.parseInt(xLevels[i]));
        }

        for (int i = 1; i < yLevels.length; i++) {
            ySet.add(Integer.parseInt(yLevels[i]));
        }

        if (xSet.contains(0)) {
            xSet.remove(0);
        } else if (ySet.contains(0)) {
            ySet.remove(0);
        }

        Set<Integer> z = new HashSet<>(xSet);
        z.addAll(ySet);

        if (z.size() != maxLevel) {
            System.out.println("Oh, my keyboard!");
        } else {
            System.out.println("I become the guy.");
        }
    }
}

// End of Code.
