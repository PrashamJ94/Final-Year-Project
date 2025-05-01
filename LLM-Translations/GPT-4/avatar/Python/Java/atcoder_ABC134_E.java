
import java.util.ArrayList;
import java.util.Scanner;

public class atcoder_ABC134_E {
    public static int binarySearch(int key, ArrayList<ArrayList<Integer>> ans) {
        int bad = -1;
        int good = ans.size();
        while (good - bad > 1) {
            int mid = (bad + good) / 2;
            if (ans.get(mid).get(ans.get(mid).size() - 1) < key) {
                good = mid;
            } else {
                bad = mid;
            }
        }
        return good;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int A = scanner.nextInt();
            int idx = binarySearch(A, ans);
            if (idx == ans.size()) {
                ArrayList<Integer> newList = new ArrayList<>();
                newList.add(A);
                ans.add(newList);
            } else {
                ans.get(idx).add(A);
            }
        }
        System.out.println(ans.size());
    }
}

// End of Code
