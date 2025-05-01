import java.util.ArrayList;
import java.util.Scanner;

public class codeforces_268_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<String[]> q = new ArrayList<>();
        int count = 0;

        for (int i = 0; i < n; i++) {
            String[] a = sc.nextLine().split(" ");
            q.add(a);
        }

        for (String[] j : q) {
            for (String[] k : q) {
                if (k == j) {
                    continue;
                } else if (j[0].equals(k[k.length - 1])) {
                    count++;
                } else {
                    continue;
                }
            }
        }

        System.out.println(count);
    }
} // End of Code
