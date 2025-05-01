import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s870655271 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int ans;

        if (N == 1 && M == 1) {
            ans = 1;
        } else if (1 < N && 1 < M) {
            ans = (N - 2) * (M - 2);
        } else {
            ans = (N * M) - 2;
        }

        System.out.println(ans);
    }

    public static int max(int... x) {
        return Arrays.stream(x).max().getAsInt();
    }

    public static int min(int... x) {
        return Arrays.stream(x).min().getAsInt();
    }

    public static int pow(int x, int y) {
        return (int) Math.pow(x, y);
    }

    public static int abs(int x) {
        return Math.abs(x);
    }

    public static int floor(int x) {
        return (int) Math.floor(x);
    }

    static class SortBy implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return Integer.compare(Math.abs(o1), Math.abs(o2));
        }
    }
}
// 
