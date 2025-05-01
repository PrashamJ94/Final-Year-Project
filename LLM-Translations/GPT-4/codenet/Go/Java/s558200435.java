
import java.util.ArrayList;
import java.util.Scanner;

public class s558200435 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        ArrayList<Integer> b = new ArrayList<Integer>();
        for (int v : a) {
            int x = binarySearch(b, v);
            if (x == b.size()) {
                b.add(v);
            } else {
                b.set(x, v);
            }
        }

        System.out.println(b.size());
    }

    private static int binarySearch(ArrayList<Integer> b, int v) {
        int left = 0;
        int right = b.size() - 1;

        while (left <= right) {
            int middle = (left + right) / 2;
            if (b.get(middle) < v) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return left;
    }
}

// 
