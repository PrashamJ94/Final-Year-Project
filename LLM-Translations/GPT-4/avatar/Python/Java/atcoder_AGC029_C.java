
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class atcoder_AGC029_C {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String[] input = sc.nextLine().split(" ");
        List<Integer> A = new ArrayList<>();
        A.add(Integer.parseInt(input[0]));
        for (int i = 1; i < input.length; i++) {
            int val = Integer.parseInt(input[i]);
            if (A.get(A.size() - 1) >= val) {
                A.add(val);
            }
        }
        int N = A.size();
        System.out.println(bis(0, N));
    }

    public static List<int[]> cut(List<int[]> array, int index) {
        if (index < 1) {
            return new ArrayList<>();
        }
        if (index <= array.get(0)[0]) {
            List<int[]> result = new ArrayList<>();
            result.add(new int[]{index, array.get(0)[1]});
            return result;
        }
        for (int i = array.size() - 1; i > 0; i--) {
            if (array.get(i - 1)[0] < index) {
                List<int[]> result = new ArrayList<>(array.subList(0, i));
                result.add(new int[]{index, array.get(i)[1]});
                return result;
            }
        }
        return array;
    }

    public static boolean is_possible(List<Integer> A, int K) {
        List<int[]> dp = new ArrayList<>();
        dp.add(new int[]{A.get(0), 0});
        for (int i = 1; i < A.size(); i++) {
            int a = A.get(i);
            if (a <= dp.get(dp.size() - 1)[0]) {
                dp = cut(dp, a);
            } else {
                dp.add(new int[]{a, 0});
            }
            boolean is_added = false;
            for (int j = dp.size() - 1; j >= 0; j--) {
                if (dp.get(j)[1] < K - 1) {
                    dp = cut(dp, dp.get(j)[0] - 1);
                    dp.add(new int[]{dp.get(j)[0], dp.get(j)[1] + 1});
                    if (dp.get(dp.size() - 1)[0] < a) {
                        dp.add(new int[]{a, 0});
                    }
                    is_added = true;
                    break;
                }
            }
            if (!is_added) {
                return false;
            }
        }
        return true;
    }

    public static int bis(int x, int y, List<Integer> A) {
        if (y == x + 1) {
            return y;
        } else if (is_possible(A, (x + y) / 2)) {
            return bis(x, (x + y) / 2, A);
        } else {
            return bis((x + y) / 2, y, A);
        }
    }
}

// End of Code
