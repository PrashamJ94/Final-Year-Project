
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC167_C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        scanner.nextLine();

        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            for (int j = 0; j < m + 1; j++) {
                c[i][j] = Integer.parseInt(input[j]);
            }
        }

        ArrayList<ArrayList<Integer>> l = new ArrayList<>();
        ArrayList<Integer> rem = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            ArrayList<ArrayList<Integer>> combinations = getCombinations(n, i);
            l.addAll(combinations);
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < l.size(); j++) {
                ArrayList<Integer> k = l.get(j);
                int ca = 0;
                for (int ii : k) {
                    ca += c[ii][i];
                }

                if (ca < x) {
                    rem.add(0, j);
                }
            }

            if (rem.size() > 0) {
                for (int j : rem) {
                    l.remove(j);
                }
                rem.clear();
            }

            if (l.size() == 0) {
                System.out.println(-1);
                break;
            }
        }

        if (l.size() > 0) {
            for (ArrayList<Integer> i : l) {
                int ca = 0;
                for (int j : i) {
                    ca += c[j][0];
                }
                if (ans == 0) {
                    ans = ca;
                } else {
                    ans = Math.min(ans, ca);
                }
            }
            System.out.println(ans);
        }
    }

    public static ArrayList<ArrayList<Integer>> getCombinations(int n, int r) {
        int[] elements = new int[n];
        for (int i = 0; i < n; i++) {
            elements[i] = i;
        }

        int[] indices = new int[r];
        for (int i = 0; i < r; i++) {
            indices[i] = i;
        }

        ArrayList<ArrayList<Integer>> combinations = new ArrayList<>();

        while (true) {
            ArrayList<Integer> combination = new ArrayList<>();
            for (int index : indices) {
                combination.add(elements[index]);
            }
            combinations.add(combination);

            int t = r - 1;
            while (t >= 0 && indices[t] == n - r + t) {
                t--;
            }

            if (t < 0) {
                break;
            }

            indices[t]++;

            for (int i = t + 1; i < r; i++) {
                indices[i] = indices[i - 1] + 1;
            }
        }

        return combinations;
    }
}

