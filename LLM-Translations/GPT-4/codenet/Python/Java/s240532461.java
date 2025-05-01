import java.util.ArrayList;
import java.util.Scanner;

public class s240532461 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();

        ArrayList<Integer> aji = new ArrayList<>();

        for (int i = 1; i <= N; i++) {
            aji.add(L + i - 1);
        }

        if (min(aji) >= 0) {
            aji.remove(aji.indexOf(min(aji)));
        } else if (max(aji) <= 0) {
            aji.remove(aji.indexOf(max(aji)));
        } else {
            aji.remove(aji.indexOf(minKeyAbs(aji)));
        }

        System.out.println(sum(aji));
    }

    private static int min(ArrayList<Integer> list) {
        int min = list.get(0);
        for (int i : list) {
            if (i < min) {
                min = i;
            }
        }
        return min;
    }

    private static int max(ArrayList<Integer> list) {
        int max = list.get(0);
        for (int i : list) {
            if (i > max) {
                max = i;
            }
        }
        return max;
    }

    private static int sum(ArrayList<Integer> list) {
        int sum = 0;
        for (int i : list) {
            sum += i;
        }
        return sum;
    }

    private static int minKeyAbs(ArrayList<Integer> list) {
        int minKey = list.get(0);
        for (int i : list) {
            if (Math.abs(i) < Math.abs(minKey)) {
                minKey = i;
            }
        }
        return minKey;
    }
}
// 
