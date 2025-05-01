//java
import java.util.Scanner;
import java.util.ArrayList;

public class s170274782 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            ArrayList<Integer> s = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                s.add(sc.nextInt());
            }
            A.add(s);
        }

        ArrayList<Integer> ans = new ArrayList<>();

        int count;
        for (int i = 0; i < N; i++) {
            ArrayList<Integer> baselis = A.get(0);
            ArrayList<Integer> groundlis = A.get(1);
            count = 0;
            count += sum(baselis, 0, i + 1) + sum(groundlis, i, N + 1);
            ans.add(count);
        }

        System.out.println(findMax(ans));
    }

    private static int sum(ArrayList<Integer> list, int start, int end) {
        int total = 0;
        for (int i = start; i < end; i++) {
            total += list.get(i);
        }
        return total;
    }

    private static int findMax(ArrayList<Integer> list) {
        int max = 0;
        for (int num : list) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
}

//
